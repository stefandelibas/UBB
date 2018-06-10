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

@WebServlet(name = "setCurrent", urlPatterns = {"/servlets/add"})
public class addCity extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String city = request.getParameter("city");
        session.setAttribute("currentCity",city);

        Repository repository = (Repository)session.getAttribute("repository");

        repository.add(city);

        RequestDispatcher dispatcher = request.getRequestDispatcher("/servlets/getNext");
        dispatcher.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
