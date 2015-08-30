
CREATE TABLE Country
(Name VARCHAR(35) NOT NULL UNIQUE,
 Code VARCHAR(4) CONSTRAINT CountryKey PRIMARY KEY,
 Capital VARCHAR(35),
 Province VARCHAR(35),
 Area NUMERIC CONSTRAINT CountryArea
   CHECK (Area >= 0),
 Population NUMERIC CONSTRAINT CountryPop
   CHECK (Population >= 0));

CREATE TABLE City
(Name VARCHAR(35),
 Country VARCHAR(4),
 Province VARCHAR(35),
 Population NUMERIC CONSTRAINT CityPop
   CHECK (Population >= 0),
 Longitude NUMERIC CONSTRAINT CityLon
   CHECK ((Longitude >= -180) AND (Longitude <= 180)) ,
 Latitude NUMERIC CONSTRAINT CityLat
   CHECK ((Latitude >= -90) AND (Latitude <= 90)) ,
 CONSTRAINT CityKey PRIMARY KEY (Name, Country, Province));

CREATE TABLE Province
(Name VARCHAR(35) CONSTRAINT PrName NOT NULL ,
 Country  VARCHAR(4) CONSTRAINT PrCountry NOT NULL ,
 Population NUMERIC CONSTRAINT PrPop
   CHECK (Population >= 0),
 Area NUMERIC CONSTRAINT PrAr
   CHECK (Area >= 0),
 Capital VARCHAR(35),
 CapProv VARCHAR(35),
 CONSTRAINT PrKey PRIMARY KEY (Name, Country));

CREATE TABLE Economy
(Country VARCHAR(4) CONSTRAINT EconomyKey PRIMARY KEY,
 GDP NUMERIC CONSTRAINT EconomyGDP
   CHECK (GDP >= 0),
 Agriculture NUMERIC,
 Service NUMERIC,
 Industry NUMERIC,
 Inflation NUMERIC);

CREATE TABLE Population
(Country VARCHAR(4) CONSTRAINT PopKey PRIMARY KEY,
 Population_Growth NUMERIC,
 Infant_Mortality NUMERIC);

CREATE TABLE Politics
(Country VARCHAR(4) CONSTRAINT PoliticsKey PRIMARY KEY,
 Independence DATE,
 Dependent  VARCHAR(4),
 Government VARCHAR(120));

CREATE TABLE Language
(Country VARCHAR(4),
 Name VARCHAR(50),
 Percentage NUMERIC CONSTRAINT LanguagePercent 
   CHECK ((Percentage > 0) AND (Percentage <= 100)),
 CONSTRAINT LanguageKey PRIMARY KEY (Name, Country));

CREATE TABLE Religion
(Country VARCHAR(4),
 Name VARCHAR(50),
 Percentage NUMERIC CONSTRAINT ReligionPercent 
   CHECK ((Percentage > 0) AND (Percentage <= 100)),
 CONSTRAINT ReligionKey PRIMARY KEY (Name, Country));

CREATE TABLE EthnicGroup
(Country VARCHAR(4),
 Name VARCHAR(50),
 Percentage NUMERIC CONSTRAINT EthnicPercent 
   CHECK ((Percentage > 0) AND (Percentage <= 100)),
 CONSTRAINT EthnicKey PRIMARY KEY (Name, Country));

CREATE TABLE Continent
(Name VARCHAR(20) CONSTRAINT ContinentKey PRIMARY KEY,
 Area NUMERIC(10));

CREATE TABLE borders
(Country1 VARCHAR(4),
 Country2 VARCHAR(4),
 Length NUMERIC 
   CHECK (Length > 0),
 CONSTRAINT BorderKey PRIMARY KEY (Country1,Country2) );

CREATE TABLE encompasses
(Country VARCHAR(4) NOT NULL,
 Continent VARCHAR(20) NOT NULL,
 Percentage NUMERIC,
   CHECK ((Percentage > 0) AND (Percentage <= 100)),
 CONSTRAINT EncompassesKey PRIMARY KEY (Country,Continent));

CREATE TABLE Organization
(Abbreviation VARCHAR(12) PRIMARY KEY,
 Name VARCHAR(80) NOT NULL,
 City VARCHAR(35) ,
 Country VARCHAR(4) , 
 Province VARCHAR(35) ,
 Established DATE,
 CONSTRAINT OrgNameUnique UNIQUE (Name));

CREATE TABLE isMember
(Country VARCHAR(4),
 Organization VARCHAR(12),
 Type VARCHAR(35) DEFAULT 'member',
 CONSTRAINT MemberKey PRIMARY KEY (Country,Organization) );

CREATE TYPE GeoCoord AS (Longitude DECIMAL, Latitude DECIMAL);

CREATE TABLE Mountain
(Name VARCHAR(35) CONSTRAINT MountainKey PRIMARY KEY,
 Mountains VARCHAR(35),
 Height NUMERIC,
 Type VARCHAR(10),
 Coordinates GeoCoord CONSTRAINT MountainCoord
     CHECK (((Coordinates).Longitude >= -180) AND 
            ((Coordinates).Longitude <= 180) AND
            ((Coordinates).Latitude >= -90) AND
            ((Coordinates).Latitude <= 90)));

CREATE TABLE Desert
(Name VARCHAR(35) CONSTRAINT DesertKey PRIMARY KEY,
 Area NUMERIC,
 Coordinates GeoCoord CONSTRAINT DesCoord
     CHECK (((Coordinates).Longitude >= -180) AND 
            ((Coordinates).Longitude <= 180) AND
            ((Coordinates).Latitude >= -90) AND
            ((Coordinates).Latitude <= 90)));

CREATE TABLE Island
(Name VARCHAR(35) CONSTRAINT IslandKey PRIMARY KEY,
 Islands VARCHAR(35),
 Area NUMERIC CONSTRAINT IslandAr check (Area >= 0),
 Height NUMERIC,
 Type VARCHAR(10),
 Coordinates GeoCoord CONSTRAINT IslandCoord
     CHECK (((Coordinates).Longitude >= -180) AND 
            ((Coordinates).Longitude <= 180) AND
            ((Coordinates).Latitude >= -90) AND
            ((Coordinates).Latitude <= 90)));

CREATE TABLE Lake
(Name VARCHAR(35) CONSTRAINT LakeKey PRIMARY KEY,
 Area NUMERIC CONSTRAINT LakeAr CHECK (Area >= 0),
 Depth NUMERIC CONSTRAINT LakeDpth CHECK (Depth >= 0),
 Altitude NUMERIC,
 Type VARCHAR(10),
 River VARCHAR(35),
 Coordinates GeoCoord CONSTRAINT LakeCoord
     CHECK (((Coordinates).Longitude >= -180) AND 
            ((Coordinates).Longitude <= 180) AND
            ((Coordinates).Latitude >= -90) AND
            ((Coordinates).Latitude <= 90)));

CREATE TABLE Sea
(Name VARCHAR(35) CONSTRAINT SeaKey PRIMARY KEY,
 Depth NUMERIC CONSTRAINT SeaDepth CHECK (Depth >= 0));

CREATE TABLE River
(Name VARCHAR(35) CONSTRAINT RiverKey PRIMARY KEY,
 River VARCHAR(35),
 Lake VARCHAR(35),
 Sea VARCHAR(35),
 Length NUMERIC CONSTRAINT RiverLength
   CHECK (Length >= 0),
 Source GeoCoord CONSTRAINT SourceCoord
     CHECK (((Source).Longitude >= -180) AND 
            ((Source).Longitude <= 180) AND
            ((Source).Latitude >= -90) AND
            ((Source).Latitude <= 90)),
 Mountains VARCHAR(35),
 SourceAltitude NUMERIC,
 Estuary GeoCoord CONSTRAINT EstCoord
     CHECK (((Estuary).Longitude >= -180) AND 
            ((Estuary).Longitude <= 180) AND
            ((Estuary).Latitude >= -90) AND
            ((Estuary).Latitude <= 90)));

CREATE TABLE geo_Mountain
(Mountain VARCHAR(35) ,
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GMountainKey PRIMARY KEY (Province,Country,Mountain) );

CREATE TABLE geo_Desert
(Desert VARCHAR(35) ,
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GDesertKey PRIMARY KEY (Province, Country, Desert) );

CREATE TABLE geo_Island
(Island VARCHAR(35) , 
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GIslandKey PRIMARY KEY (Province, Country, Island) );

CREATE TABLE geo_River
(River VARCHAR(35) , 
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GRiverKey PRIMARY KEY (Province ,Country, River) );

CREATE TABLE geo_Sea
(Sea VARCHAR(35) ,
 Country VARCHAR(4)  ,
 Province VARCHAR(35) ,
 CONSTRAINT GSeaKey PRIMARY KEY (Province, Country, Sea) );

CREATE TABLE geo_Lake
(Lake VARCHAR(35) ,
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GLakeKey PRIMARY KEY (Province, Country, Lake) );

CREATE TABLE geo_Source
(River VARCHAR(35) ,
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GSourceKey PRIMARY KEY (Province, Country, River) );

CREATE TABLE geo_Estuary
(River VARCHAR(35) ,
 Country VARCHAR(4) ,
 Province VARCHAR(35) ,
 CONSTRAINT GEstuaryKey PRIMARY KEY (Province, Country, River) );

CREATE TABLE mergesWith
(Sea1 VARCHAR(35) ,
 Sea2 VARCHAR(35) ,
 CONSTRAINT MergesWithKey PRIMARY KEY (Sea1, Sea2) );

CREATE TABLE located
(City VARCHAR(35) ,
 Province VARCHAR(35) ,
 Country VARCHAR(4) ,
 River VARCHAR(35),
 Lake VARCHAR(35),
 Sea VARCHAR(35) );

CREATE TABLE locatedOn
(City VARCHAR(35) ,
 Province VARCHAR(35) ,
 Country VARCHAR(4) ,
 Island VARCHAR(35) ,
 CONSTRAINT locatedOnKey PRIMARY KEY (City, Province, Country, Island) );

CREATE TABLE islandIn
(Island VARCHAR(35) ,
 Sea VARCHAR(35) ,
 Lake VARCHAR(35) ,
 River VARCHAR(35) );

CREATE TABLE MountainOnIsland
(Mountain VARCHAR(35),
 Island  VARCHAR(35),
 CONSTRAINT MntIslKey PRIMARY KEY (Mountain, Island) );
