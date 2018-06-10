using ASP_MVC.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace ASP_MVC.DataAbstractionLayer
{
    public class DAL
    {

        public Client GetClient(string username, string password)
        {
            try
            {
                SqlConnection conn =
                    new SqlConnection(
                        "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");

                var sql = new SqlCommand("select * from Clients where Username=@username and Password=@password",
                    conn);

                sql.Parameters.AddWithValue("@username", username);
                sql.Parameters.AddWithValue("@password", password);

                conn.Open();

                var result = sql.ExecuteReader();
                Client client = new Client();
                if (result.Read())
                {
                    client.IDClient = result.GetInt32(0);
                    client.ClientName = result.GetString(1);
                    client.Username = result.GetString(2);
                    client.Password = result.GetString(3);
                    return client;
                }

                result.Close();
                return null;
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return null;
        }

        internal List<Room> GetPriced(string min, string max)
        {
            List<Room> rooms = new List<Room>();
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");
                string sqltext = "select top 4 IDRoom,HotelName,Price,Type,Category from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " where r.IDRoom > 0";
                if (min != null && min != "")
                    sqltext += " and r.Price > @MinPrice ";
                if (max != null  && max != "")
                    sqltext += " and r.Price < @MaxPrice ";
                var sql = new SqlCommand(sqltext + " order by r.IDRoom ", conn);
                if (min != null)
                    sql.Parameters.AddWithValue("@MinPrice", min);
                if (max != null)
                    sql.Parameters.AddWithValue("@MaxPrice", max);
                
                conn.Open();

                var result = sql.ExecuteReader();
                while (result.Read())
                {
                    Room room = new Room();
                    room.IDRoom = result.GetInt32(0);
                    room.Hotel = result.GetString(1);
                    room.Price = result.GetInt32(2);
                    room.Type = result.GetString(3);
                    room.Category = result.GetString(4);
                    rooms.Add(room);
                }

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return rooms;
        }

        internal void DeleteBooking(string bid,string cid)
        {
            try
            {
                SqlConnection conn =
                    new SqlConnection(
                        "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");

                var sql = new SqlCommand("delete from Bookings" +
                    " where IDBooking=@IDBooking and IDClient=@IDClient", conn);

                sql.Parameters.AddWithValue("@IDBooking", bid);
                sql.Parameters.AddWithValue("@IDClient", cid);

                conn.Open();

                sql.ExecuteNonQuery();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        internal void SaveBooking(string id,string cid, string start, string end)
        {
            try
            {
                SqlConnection conn =
                    new SqlConnection(
                        "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");

                var sql = new SqlCommand("insert into Bookings(IDRoom,IDClient,startDate,endDate)" +
                    " values(@IDRoom,@IDClient,@start,@end)", conn);

                sql.Parameters.AddWithValue("@IDRoom", id);
                sql.Parameters.AddWithValue("@IDClient", cid);
                sql.Parameters.AddWithValue("@start", start);
                sql.Parameters.AddWithValue("@end", end);

                conn.Open();

                sql.ExecuteNonQuery();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        internal Room GetRoom(string id)
        {
            Room room = null;
            try
            {
                SqlConnection conn =
                    new SqlConnection(
                        "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");

                var sql = new SqlCommand("select IDRoom,HotelName,Price,Type,Category from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " where r.IDRoom > @IDRoom",
                    conn);

                sql.Parameters.AddWithValue("@IDRoom", id);

                conn.Open();

                var result = sql.ExecuteReader();
                if (result.Read())
                {
                    room = new Room();
                    room.IDRoom = result.GetInt32(0);
                    room.Hotel = result.GetString(1);
                    room.Price = result.GetInt32(2);
                    room.Type = result.GetString(3);
                    room.Category = result.GetString(4);
                }

                result.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return room; 
        }

        internal string getHotel(int iDHotel)
        {
            string name = "";
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");

                var sql = new SqlCommand("select HotelName from Hotels where IDHotel=@IDHotel ", conn);
                sql.Parameters.AddWithValue("@IDHotel",iDHotel);
                conn.Open();

                var result = sql.ExecuteReader();
                result.Read();

                name = result.GetString(0);

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
            
            return name;
        }
        internal List<Room> GetRooms(string hotel, string type, string category)
        {
           
            List<Room> rooms = new List<Room>();
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");
                string sqltext = "select top 4 IDRoom,HotelName,Price,Type,Category from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " where r.IDRoom > 0";
                if (hotel != "")
                    sqltext += " and h.HotelName=@HotelName ";
                if (type != "")
                    sqltext += " and r.Type=@Type ";
                if (category != "")
                    sqltext += " and r.Category=@Category ";
                var sql = new SqlCommand(sqltext +
                    " order by r.IDRoom ", conn);
                if (hotel != "")
                    sql.Parameters.AddWithValue("@HotelName", hotel);
                if (type != "")
                    sql.Parameters.AddWithValue("@Type", type);
                if (category != "")
                    sql.Parameters.AddWithValue("@Category", category);
                
                conn.Open();

                var result = sql.ExecuteReader();
                while (result.Read())
                {
                    Room room = new Room();
                    room.IDRoom = result.GetInt32(0);
                    room.Hotel = result.GetString(1);
                    room.Price = result.GetInt32(2);
                    room.Type = result.GetString(3);
                    room.Category = result.GetString(4);
                    rooms.Add(room);
                }

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return rooms;
        }
        internal List<Room> GetRooms(string sid,string hotel,string type,string category)
        {
            int id = 0;
            if (sid != "" || sid != "0")
                id = Int32.Parse(sid);
            List<Room> rooms = new List<Room>();
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");
                string sqltext = "select top 4 IDRoom,HotelName,Price,Type,Category from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " where r.IDRoom > @FirstID";
                if (hotel != "")
                    sqltext += " and h.HotelName=@HotelName ";
                if (type != "")
                    sqltext += " and r.Type=@Type";
                if (category != "")
                    sqltext += " and r.Category=@Category";
                var sql = new SqlCommand(sqltext+
                    " order by r.IDRoom ",conn);
                if (hotel != "")
                    sql.Parameters.AddWithValue("@HotelName",hotel);
                if (type != null)
                    sql.Parameters.AddWithValue("@Type", type);
                if (category != null)
                    sql.Parameters.AddWithValue("@Category", category);

                sql.Parameters.AddWithValue("@FirstID", id);

                conn.Open();

                var result = sql.ExecuteReader();
                while (result.Read())
                {
                    Room room = new Room();
                    room.IDRoom = result.GetInt32(0);
                    room.Hotel = result.GetString(1);
                    room.Price = result.GetInt32(2);
                    room.Type = result.GetString(3);
                    room.Category = result.GetString(4);
                    rooms.Add(room);
                }

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return rooms;
        }
        internal List<Room> GetRooms(string sid, string hotel, string type, string category,bool back)
        {
            int id = 0;
            if (sid != "")
                id = Int32.Parse(sid);
            List<Room> rooms = new List<Room>();
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");
                string sqltext = "select top 4 IDRoom,HotelName,Price,Type,Category from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " where r.IDRoom < @FirstID";
                if (hotel != "")
                    sqltext += " and h.HotelName=@HotelName ";
                if (type != "")
                    sqltext += " and r.Type=@Type";
                if (category != "")
                    sqltext += " and r.Category=@Category";
                var sql = new SqlCommand(sqltext +
                    " order by r.IDRoom desc ", conn);
                if (hotel != "")
                    sql.Parameters.AddWithValue("@HotelName", hotel);
                if (type != null)
                    sql.Parameters.AddWithValue("@Type", type);
                if (category != null)
                    sql.Parameters.AddWithValue("@Category", category);

                sql.Parameters.AddWithValue("@FirstID", id);

                conn.Open();

                var result = sql.ExecuteReader();
                while (result.Read())
                {
                    Room room = new Room();
                    room.IDRoom = result.GetInt32(0);
                    room.Hotel = result.GetString(1);
                    room.Price = result.GetInt32(2);
                    room.Type = result.GetString(3);
                    room.Category = result.GetString(4);
                    rooms.Add(room);
                }

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return rooms;
        }
        internal List<Room> GetRooms()
        {
           
            List<Room> rooms = new List<Room>();
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");
                SqlCommand sql = new SqlCommand("select top 4 IDRoom,HotelName,Price,Type,Category from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " order by r.IDRoom ", conn);
                
                conn.Open();

                var result = sql.ExecuteReader();
                while (result.Read())
                {
                    Room room = new Room();
                    room.IDRoom = result.GetInt32(0);
                    room.Hotel = result.GetString(1);
                    room.Price = result.GetInt32(2);
                    room.Type = result.GetString(3);
                    room.Category = result.GetString(4);
                    rooms.Add(room);
                }

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
            return rooms;
        }
        public List<Booking> GetBookings(int IDClient)
        {
            List<Booking> bookings = new List<Booking>();
            try
            {
                SqlConnection conn =
                   new SqlConnection(
                       "Data Source = DESKTOP-FU69766\\SQLEXPRESS; Initial Catalog = hotelchain; Integrated Security = SSPI");

                var sql = new SqlCommand("select b.IDBooking,r.IDRoom,IDClient,HotelName,Price,Type,Category,startDate,endDate from Rooms as r" +
                    " join Hotels as h on r.IDHotel = h.IDHotel " +
                    " join Bookings as b on b.IDRoom = r.IDRoom" + 
                    " where IDClient = @IDClient" +
                    " order by b.startDate ", conn);

                sql.Parameters.AddWithValue("@IDClient", IDClient);

                conn.Open();

                var result = sql.ExecuteReader();
                while (result.Read())
                {
                    Booking booking = new Booking();
                    booking.IDBooking = result.GetInt32(0);
                    booking.IDRoom = result.GetInt32(1);
                    booking.IDClient = result.GetInt32(2);
                    booking.Hotel = result.GetString(3);
                    booking.Price = result.GetInt32(4);
                    booking.Type = result.GetString(5);
                    booking.Category = result.GetString(6);
                    booking.startDate = result.GetDateTime(7);
                    booking.endDate = result.GetDateTime(8);

                    bookings.Add(booking);
                }

                result.Close();
                conn.Close();
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }

            return bookings;
        }
    }
}

        
