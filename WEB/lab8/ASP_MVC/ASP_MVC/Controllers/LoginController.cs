using ASP_MVC.DataAbstractionLayer;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP_MVC.Controllers
{
    public class LoginController : Controller
    {
        // GET: Login
        public ActionResult Login()
        {
            return View();
        }

        public ActionResult EnterApplication()
        {
            DAL dal = new DAL();
            string username = Request.Params["username"];
            string password = Request.Params["password"];

            if (dal.GetClient(username, password) != null)
            {
                int id = dal.GetClient(username, password).IDClient;
                Session["id"] = id;
                return Redirect("~/Rooms/Rooms");
            }
            else
            {
                return RedirectToAction("Login");
            }

        }

    }
}