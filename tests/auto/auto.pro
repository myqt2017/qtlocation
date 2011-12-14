TEMPLATE = subdirs

#Place unit tests
SUBDIRS += qplace \
           qplacecategory \
           qplacecontactdetail \
           qplacecontentrequest \
           qplacedetailsreply \
           qplaceeditorial \
           qplacemanager \
           qplacemanager_nokia \
           qplaceimage \
           qplaceratings \
           qplacereview \
           qplacesearchrequest \
           qplacesupplier \
           qplacesearchresult \
           qplaceuser \
           qmlinterface

SUBDIRS += geotestplugin \
           positionplugin \
           positionplugintest \
           qgeocodingmanagerplugins \
           qgeoaddress \
           qgeoareamonitor \
           qgeoboundingbox \
           qgeoboundingcircle \
           qgeocodereply \
           qgeocodingmanager \
           qgeocoordinate \
           qgeolocation \
           qgeomaneuver \
           qgeopositioninfo \
           qgeopositioninfosource \
           qgeoroute \
           qgeoroutereply \
           qgeorouterequest \
           qgeosatelliteinfo \
           qgeosatelliteinfosource \
           qnmeapositioninfosource \
           declarative_core \
           maptype

!mac: SUBDIRS += declarative_ui

contains(config_test_jsondb, yes) {
    SUBDIRS += qplacemanager_jsondb
}
