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

@WebServlet(name = "SetCurrentCity", urlPatterns = {"/servlets/set"})
public class SetCurrentCity extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String city = request.getParameter("city");
        session.setAttribute("currentCity",city);


        Repository repository = (Repository)session.getAttribute("repository");
        if(repository.getRoute() == null)
            repository.setRoute(city);
        else
            repository.setCurrentCity(city);

        RequestDispatcher dispatcher = request.getRequestDispatcher("/servlets/getNext");
        dispatcher.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}

