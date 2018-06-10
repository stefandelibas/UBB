package servlets;

import repo.Repository;

import java.io.IOException;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Set;
import java.util.Stack;

@WebServlet(name = "getNextDestination", urlPatterns = {"/servlets/getNext"})
public class getNextDestination extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        HttpSession session = request.getSession();
        String city = (String)session.getAttribute("currentCity");
        Repository repository = (Repository)session.getAttribute("repository");
        if(repository == null)
        {
            repository = new Repository(city);
            session.setAttribute("repository",repository);
        }
        ArrayList<String> citiesOnRoute = repository.getCitiesOnRoute();

        session.setAttribute("citiesOnRoute",citiesOnRoute);

        ArrayList<String> connections = repository.getAvailableCities(city);

        RequestDispatcher rd = null;

        session.setAttribute("currentConnections", connections);

        rd = request.getRequestDispatcher("/mainPage.jsp");

        rd.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
