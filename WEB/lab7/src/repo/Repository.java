package repo;

import model.Route;

import java.sql.*;
import java.util.*;

public class Repository {

    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/routes";

    static final String DbUser = "root";
    static final String DbPassword = "";
     private Route route;

    public Repository(String startingCity) {
        this.route = new Route(startingCity);
    }
    public Repository() {
    }

    public void setRoute(String startingCity)
    {
        if(this.route == null)
            this.route = new Route(startingCity);
    }
    public Route getRoute()
    {
        return this.route;
    }

    public void add(String city)
    {
        route.getCities().add(city);
    }

    public void back()
    {
        if(!this.inStartingCity())
            route.getCities().remove(route.getCities().size()-1);
    }
    public boolean inStartingCity()
    {
        return this.route.getCities().size() == 1;
    }

    public void setCurrentCity(String newCity)
    {
        this.route.setCurrentCity(newCity);
    }
    public String getStartingCity()
    {
        return this.route.getStartingCity();
    }

    public String getCurrentCity()
    {
        return this.route.getCurrentCity();
    }

    public ArrayList<String> getCitiesOnRoute()
    {
        return this.route.getCities();
    }

    public ArrayList<String> getAvailableCities(String city)
    {
        Connection conn = null;
        Statement stmt = null;
        ArrayList<String> connections = new ArrayList<>();

        try {
            Class.forName("com.mysql.jdbc.Driver");

            conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

            stmt = conn.createStatement();
            String sql = "select DISTINCT city2 FROM connections WHERE city1='" + city + "'";
            ResultSet rs = stmt.executeQuery(sql);


            while(rs.next())
            {
                connections.add(rs.getString("city2"));
            }

            rs.close();
            stmt.close();
            conn.close();
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
        finally {
            try {
                if (stmt != null) {
                    stmt.close();
                }
            } catch (SQLException ex2) {}
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException ex2) {}
        }

        return connections;
    }

    public List<String> getAll()
    {
        Connection conn = null;
        Statement stmt = null;
        ArrayList<String> cities = new ArrayList<>();

        try {
            Class.forName("com.mysql.jdbc.Driver");

            conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

            stmt = conn.createStatement();
            String sql = "select DISTINCT city1 FROM connections ORDER BY city1";
            ResultSet rs = stmt.executeQuery(sql);

            while(rs.next())
            {
                cities.add(rs.getString("city1"));
            }

            rs.close();
            stmt.close();
            conn.close();
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
        finally {
            try {
                if (stmt != null) {
                    stmt.close();
                }
            } catch (SQLException ex2) {}
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException ex2) {}
        }

        return cities;
    }

}
