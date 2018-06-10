package model;

import java.util.ArrayList;
import java.util.Stack;

public class Route {
    String startingCity;
    String currentCity;
    ArrayList<String> cities;

    public Route(String startingCity) {
        this.startingCity = startingCity;
        this.currentCity = startingCity;
        this.cities = new ArrayList<>();
        this.cities.add(startingCity);
    }

    public String getStartingCity() {
        return startingCity;
    }

    public void setStartingCity(String startingCity) {
        this.startingCity = startingCity;
    }

    public ArrayList<String> getCities() {
        return cities;
    }

    public void setCities(ArrayList<String> cities) {
        this.cities = cities;
    }
    public String getCurrentCity() {
        return currentCity;
    }

    public void setCurrentCity(String currentCity) {
        this.currentCity = currentCity;
    }

    @Override
    public String toString() {
        return "Route{" +
                "startingCity='" + startingCity + '\'' +
                ", cities=" + cities +
                '}';
    }


}
