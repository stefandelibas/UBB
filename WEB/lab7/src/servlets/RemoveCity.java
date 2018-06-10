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

@WebServlet(name = "RemoveCity", urlPatterns = {"/servlets/remove"})
public class RemoveCity extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        Repository repository = (Repository)session.getAttribute("repository");
        repository.back();

        String city = repository.getCitiesOnRoute().get(repository.getCitiesOnRoute().size()-1);
        session.setAttribute("currentCity",city);

        RequestDispatcher dispatcher = request.getRequestDispatcher("/servlets/getNext");
        dispatcher.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}

