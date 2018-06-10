package servlets;

import repo.Repository;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;

@WebServlet(name = "endRoute", urlPatterns = {"/servlets/endRoute"})
public class endRoute extends HttpServlet {
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/routes";

    static final String DbUser = "root";
    static final String DbPassword = "";

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        Repository repository = (Repository)session.getAttribute("repository");

        session.setAttribute("finalRoute",repository.getCitiesOnRoute());

        String r = "";
        ArrayList<String> citiesOnRoute = repository.getCitiesOnRoute();
        for(int i=0;i<citiesOnRoute.size();i++) {
            r += citiesOnRoute.get(i);
            if (i != citiesOnRoute.size() - 1)
                r += " -> ";
        }

        Connection conn = null;
        Statement stmt = null;
        ArrayList<String> connections = new ArrayList<>();

        try {
            Class.forName("com.mysql.jdbc.Driver");

            conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

            PreparedStatement statement = conn.prepareStatement("INSERT INTO routes(route) values(?)");
            statement.setString(1, r);
            statement.executeUpdate();

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



        RequestDispatcher dispatcher = request.getRequestDispatcher("/route.jsp");
        dispatcher.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}

