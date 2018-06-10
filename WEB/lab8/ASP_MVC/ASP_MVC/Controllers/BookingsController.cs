using ASP_MVC.DataAbstractionLayer;
using ASP_MVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP_MVC.Controllers
{
    public class BookingsController : Controller
    {
        // GET: Bookings
        public ActionResult Bookings()
        {
            return View();
        }
        public JsonResult GetBookings()
        {
            string id = (string)Request.Params["id"];
            DAL dal = new DAL();
            List<Booking> list = dal.GetBookings(Int32.Parse(id));
            return Json(list, JsonRequestBehavior.AllowGet);
        }
        public JsonResult DeleteBooking()
        {
            string bid = (string)Request.Params["bid"];
            string cid = (string)Request.Params["cid"];
            DAL dal = new DAL();
            try
            {
                dal.DeleteBooking(bid,cid);
            }
            catch(Exception ex)
            {
                return Json("Error", JsonRequestBehavior.AllowGet);
            }
            return Json("Succes", JsonRequestBehavior.AllowGet);
        }
    }
}