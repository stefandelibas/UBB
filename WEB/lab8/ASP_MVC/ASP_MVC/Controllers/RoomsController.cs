using ASP_MVC.DataAbstractionLayer;
using ASP_MVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP_MVC.Controllers
{
    public class RoomsController : Controller
    {
        // GET: Rooms
        public ActionResult Rooms()
        {
            return View();
        }

        public JsonResult GetRooms()
        {
            List<Room> rooms=null;
            DAL dal = new DAL();
            
            string hotel = (string)Request["hotel"];
            string type = (string)Request["type"];
            string cat = (string)Request["category"];

            rooms = dal.GetRooms(hotel,type,cat);
        
            return Json(rooms, JsonRequestBehavior.AllowGet);
            
           
        }
        public JsonResult Next()
        {
            DAL dal = new DAL();

            string id = (string)Request["rid"];
            string hotel = (string)Request["hotel"];
            string type = (string)Request["type"];
            string cat = (string)Request["category"];

            List<Room> rooms = dal.GetRooms(id,hotel,type,cat);
            return Json(rooms, JsonRequestBehavior.AllowGet);
        }
        public JsonResult Prev()
        {
            DAL dal = new DAL();

            string id = (string)Request["rid"];
            string hotel = (string)Request["hotel"];
            string type = (string)Request["type"];
            string cat = (string)Request["category"];

            List<Room> rooms = dal.GetRooms(id, hotel, type, cat,true);
            rooms.Reverse();
            return Json(rooms, JsonRequestBehavior.AllowGet);
        }
    }
}