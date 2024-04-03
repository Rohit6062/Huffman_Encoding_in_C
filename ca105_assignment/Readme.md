# ca105_assignment

# <center>INTERCITY EXPRESS TRAINS</center>

## Member Contributions
   - ### Shashi Ranjan Kumar
       * ER Diagram, Creation of Relational Schema, Insertion of data into tables.
  - ### Ankit Kumar
      * Relations from ER diagram, Insertion of data into tables.
  - ### Biprojeet Choudhary
      * Data Collection and Organization.
## Entity Relationship Diagram

<img
  src="./SmartSelect_20240208_125029_Samsung Notes.jpg"
  alt="Alt text"
  title="Optional title"
  style="display: inline-block; margin: 0 auto;width: 100%;height:100%;padding:10px">
<hr>

## Relations

Routes(Route_no,Route_name,time_taken,total_dist,Start_Stn,Start_time,End_Stn,End_time)
 
Stations(Station_code,Station_name,No_of_Platform,State)
 
Trains(Train_no,Train_name,Capacity,Route_no)
 
Coaches(coach_no,made_by,last_maintained,mileage)
 
Active_Coaches(Coach_no,Train_no,Date)
 
Standby_Coaches(Coach_no,Date)
 
Maintainance(Maintain_no,Maintain_date,Maintain_type,Coach_no)
 
Tickets(Ticket_no,Train_no,Status,passenger_name,Age,Board_stn,drop_stn,date_of_journey,booking_date,fare,discount,
          travel_agent_id,agent_comm)
 
Travel_Agents(Travel_Agent_Id,Travel_Agent_Name,ADD,MOB,Email)
 
Staffs(Staff_no,Staff_name,Contact_no,residence_city)
 
Seats(Seat_no,Seat_type)
 
Staff_schedule(Route_no,Train_no,Driver_no,Remark,Time,Date,Accomodation)
 
Train_schedule(Route_no,Train_no,Station_code,Date,ETA,AAT,EDT,ADT)
 
Seat_allocated(Ticket_no,Coach_no,Seat_no,Seat_type,Date,Time)
 
Train_coaches(Train_no,Coach_no,Date_from)

```sql
create database intercity_express_trains;
```

```sql
create table active_coaches(coach_no varchar(10) primary key,train_no int,foreign key(train_no) references trains(train_no));
```
```sql
create table coaches(coach_no varchar(10) primary key,manufacturer varchar(50),last_maintained date,mileage int);
```
```sql
create table maintainance(maintain_no varchar(10) primary key,maintain_type varchar(20),maintain_date date,coach_no varchar(10),foreign key(coach_no) references coaches(coach_no));
```
```sql
create table routes(route_no varchar(10) primary key,route_name varchar(30),time_taken time,total_dist_km int,start_stn varchar(10),start_time time,end_stn varchar(10),end_time time,foreign key(start_stn) references stations(station_code),foreign key(end_stn) references stations(station_code));
```
```sql
create table seat_allocated(ticket_no varchar(10),coach_no varchar(10),seat_no int,seat_type varchar(10),Date date,Time time,foreign key(ticket_no) references tickets(ticket_no),foreign key(coach_no) references active_coaches(coach_no),foreign key(seat_no) references seats(seat_no),primary key(ticket_no,Date,Time));
```
```sql
create table staff_schedule(route_no varchar(10),train_no int,staff_no varchar(10),remark varchar(20),date date,time time,accomodation varchar(10),foreign key(route_no) references routes(route_no),foreign key(train_no) references trains(train_no),foreign key(staff_no) references staffs(staff_no),primary key(route_no,train_no,staff_no,date));
```
```sql
create table staffs(staff_no varchar(10) primary key,staff_name varchar(20),contact_no varchar(15),residence_city varchar(20));
```
```sql
create table standby_coaches(coach_no varchar(10),Date date,primary key(coach_no,date),foreign key(coach_no) references coaches(coach_no));
```
```sql
create table stations(station_code varchar(10) primary key,station_name varchar(30),no_of_platform int,state varchar(20));

```
```sql
create table tickets(ticket_no varchar(10) primary key,train_no int,status varchar(10),passenger_name varchar(30),age int,passenger_type enum("child","adult","senior-citizen"),board_stn varchar(10),drop_stn varchar(10),date_of_journey date,booking_date date,fare float(2),discount float(2),travel_agent_id varchar(10),agent_comm float(2),foreign key(train_no) references trains(train_no),foreign key(board_stn) references stations(station_code), foreign key(drop_stn) references stations(station_code),foreign key(travel_agent_id) references travel_agents(travel_agent_id));
```
```sql
create table train_coaches(train_no int,coach_no varchar(10),date_from date,date_to date,foreign key(train_no) references trains(train_no),foreign key(coach_no) references active_coaches(coach_no),primary key(train_no,coach_no,date_from,date_to));

```
```sql
create table train_schedule(route_no varchar(10),train_no int,station_code varchar(10),Date date,EAT time,AAT time,EDT time,ADT time,foreign key(route_no) references routes(route_no),foreign key(train_no) references trains(train_no),foreign key(station_code) references stations(station_code),primary key(route_no,train_no,station_code,Date));
```
```sql
create table trains(train_no int primary key,train_name varchar(30),capacity int,route_no varchar(10) not null,foreign key(route_no) references routes(route_no));
```
```sql
create table travel_agents(travel_agent_id varchar(10) primary key,travel_agent_name varchar(30),address varchar(50),contactno varchar(15),email varchar(30));
```
```sql
create table seats(seat_no int primary key,type varchar(20));
```
<hr>

## Insert Statements

```sql
insert into trains(train_no,train_name,capacity,route_no) values ('22945','SAURASHTRA MAIL',90,"RT001"),('14553','HIMACHAL EXPRESS',90,"RT002"),('11019','KONARK EXPRESS',90,"RT003"),('22223','SHIRDI VANDEBHARAT EXPRESS',90,"RT004"),(11301,"UDYAN EXPRESS",90,"RT005"),(12715,"SACHKHAND EXPRESS",90,"RT006"),(19628,"AJMER SUPERFAST EXPRESS",90,"RT007"),(17325,"VISHWAMANAVA EXPRESS",90,"RT008"),(18234,"NARMADA EXPRESS",90,"RT009"),(10103,"MANDOVI EXPRESS",90,"RT010"),(13022,"MITHILA EXPRESS",90,"RT011"),('22946','SAURASHTRA MAIL',90,"RT014"),('14552','HIMACHAL EXPRESS',90,"RT015"),('11020','KONARK EXPRESS',90,"RT016"),('22222','SHIRDI VANDEBHARAT EXPRESS',90,"RT017"),(11302,"UDYAN EXPRESS",90,"RT018"),(12716,"SACHKHAND EXPRESS",90,"RT019"),(19627,"AJMER SUPERFAST EXPRESS",90,"RT020"),(17326,"VISHWAMANAVA EXPRESS",90,"RT021"),(18235,"NARMADA EXPRESS",90,"RT022"),(10102,"MANDOVI EXPRESS",90,"RT023"),(13021,"MITHILA EXPRESS",90,"RT024");

```

```sql
INSERT INTO travel_agents (travel_agent_id, travel_agent_name, address, contactno, email) VALUES
('TA001', 'Aarav Gupta', 'New Delhi', '+91 12345 67890', 'aarav@example.com'),
('TA002', 'Mira Patel', 'Mumbai', '+91 98765 43210', 'mira@example.com'),
('TA003', 'Krish Sharma', 'Bengaluru', '+91 11122 23333', 'krish@example.com'),
('TA004', 'Ishaan Kumar', 'Chennai', '+91 44455 56666', 'ishaan@example.com'),
('TA005', 'Anaya Singh', 'Kolkata', '+91 77788 89999', 'anaya@example.com'),
('TA006', 'Diya Mishra', 'Hyderabad', '+91 99900 01111', 'diya@example.com'),
('TA007', 'Kabir Khan', 'Pune', '+91 22233 34444', 'kabir@example.com'),
('TA008', 'Riya Thakur', 'Jaipur', '+91 55566 67777', 'riya@example.com'),
('TA009', 'Aryan Choudhary', 'Ahmedabad', '+91 88899 00000', 'aryan@example.com'),
('TA010', 'Avni Agarwal', 'Kochi', '+91 66677 88888', 'avni@example.com'),
('TA011', 'Rehan Malhotra', 'Chandigarh', '+91 33344 45555', 'rehan@example.com'),
('TA012', 'Sia Verma', 'Lucknow', '+91 00011 12222', 'sia@example.com'),
('TA013', 'Kabir Gupta', 'Goa', '+91 11122 23333', 'kabir@example.com'),
('TA014', 'Anika Rajput', 'Indore', '+91 22233 34444', 'anika@example.com'),
('TA015', 'Veer Singh', 'Jaipur', '+91 33344 45555', 'veer@example.com');

```

```sql
INSERT INTO stations (station_code, station_name, no_of_platform, state) VALUES
('PUNE', 'Pune', 6, 'MAHARASHTRA'),
('CSMT', 'MUMBAI', 12, 'MAHARASHTRA'),
('JAM', 'GANDHINAGAR', 10, 'GUJARAT'),
('ST', 'SURAT', 6, 'GUJARAT'),
('SINA', 'SRINAGAR', 7, 'JAMMU-KASHMIR'),
('SNSI', 'SAINAGAR SHIRDI TERMINUS', 6, 'MAHARASHTRA'),
('SUR', 'SOLAPUR', 5, 'MAHARASHTRA'),
('SOP', 'SHIVPUR', 3, 'MAHARASHTRA'),
('VSG', 'GOA', 8, 'GOA'),
('NDLS', 'NEW DELHI', 15, 'NEW DELHI'),
('UHL', 'UNA HIMACHAL', 7, 'HIMACHAL PRADESH'),
('LJN', 'LUCKNOW', 12, 'UTTAR PRADESH'),
('SC', 'SECUNDERABAD', 12, 'ANDHRA PRADESH'),
('VSKP', 'VISHAKHAPATNAM', 20, 'ANDHRA PRADESH'),
('BSB', 'VARANASI', 12, 'UTTAR PRADESH'),
('BPL', 'BHOPAL', 5, 'MADHYA PRADESH'),
('INDB', 'INDORE', 6, 'MADHYA PRADESH'),
('LNL', 'LONAVALA', 4, 'MAHARASHTRA'),
('AII', 'AJMER', 7, 'RAJASTHAN'),
('DWR', 'DHARWAD', 6, 'KARNATAKA'),
('SBC', 'BENGALURU', 20, 'KARNATAKA'),
('NGP', 'NAGPUR', 9, 'MAHARASHTRA'),
('MFP', 'MUZAFFARPUR', 8, 'BIHAR'),
('PNBE', 'PATNA', 10, 'BIHAR'),
('RXL', 'RAXAUL', 8, 'BIHAR'),
('BUI', 'BALLIA', 6, 'UTTAR PRADESH'),
('GKP', 'GORAKHPUR', 15, 'UTTAR PRADESH'),
('PRYJ', 'PRAYAGRAJ', 8, 'UTTAR PRADESH'),
('HWH', 'HOWRAH', 20, 'WEST BENGAL'),
('CNB', 'KANPUR', 11, 'UTTAR PRADESH'),
('BCT', 'Mumbai Central', 8, 'Maharashtra'),
('MAA', 'Chennai Central', 14, 'Tamil Nadu'),
('MAS', 'Chennai Terminus', 10, 'Tamil Nadu'),
('MMCT', 'Mumbai Central Terminus', 9, 'Maharashtra'),
('YPR', 'Yesvantpur Main', 7, 'Karnataka'),
('ADI', 'Ahmedabad Main', 9, 'Gujarat'),
('JP', 'Jaipur Main', 6, 'Rajasthan'),
('LTT', 'Lokmanya Tilak Main', 9, 'Maharashtra');


```

```sql
INSERT INTO ROUTES (route_no, route_name, time_taken, total_dist_km, start_stn, start_time, end_stn, end_time) VALUES
("RT001", "MUMBAI CENTRAL-GANDHINAGAR", '05:40:00', 548, "CSMT", '09:00:00', "JAM", '14:40:00'),
("RT014", "GANDHINAGAR-MUMBAI CENTRAL", '05:40:00', 548, "JAM", '16:40:00', "CSMT", '22:20:00'),
("RT002", "NEW DELHI-HIMACHAL", '06:10:00', 412, "NDLS", '07:00:00', "UHL", '13:10:00'),
("RT015", "HIMACHAL-NEW DELHI", '06:10:00', 412, "UHL", '16:10:00', "NDLS", '22:20:00'),
("RT003", "SECUNDERABAD-VISAKHAPATNAM", '08:30:00', 500, "SC", '10:00:00', "VSKP", '18:30:00'),
("RT016", "VISAKHAPATNAM-SECUNDERABAD", '08:30:00', 500, "VSKP", '21:30:00', "SC", '06:00:00'),
("RT004", "MUMBAI-SAINAGAR SHIRDI", '05:20:00', 248, "CSMT", '11:40:00', "SNSI", '05:00:00'),
("RT017", "SAINAGAR SHIRDI-MUMBAI", '05:20:00', 248, "SNSI", '07:00:00', "CSMT", '12:20:00'),
("RT005", "MUMBAI-SOLAPUR", '06:35:00', 400, "CSMT", '08:25:00', "SUR", '15:00:00'),
("RT018", "SOLAPUR-MUMBAI", '06:35:00', 400, "SUR", '17:00:00', "CSMT", '23:35:00'),
("RT006", "BHOPAL-DELHI", '07:45:00', 700, "BPL", '20:15:00', "NDLS", '04:00:00'),
("RT019", "DELHI-BHOPAL", '07:45:00', 700, "NDLS", '06:00:00', "BPL", '13:45:00'),
("RT007", "LONAVALA-AJMER", '10:45:00', 1062, "LNL", '02:15:00', "AII", '13:00:00'),
("RT020", "AJMER-LONAVALA", '10:45:00', 1062, "AII", '16:00:00', "LNL", '02:45:00'),
("RT008", "DHARWAD-BENGALURU", '05:00:00', 432, "DWR", '05:00:00', "SBC", '10:00:00'),
("RT021", "BENGALURU-DHARWAD", '05:00:00', 432, "SBC", '12:00:00', "DWR", '17:00:00'),
("RT009", "BHOPAL-INDORE", '03:00:00', 246, "BPL", '21:15:00', "INDB", '00:15:00'),
("RT022", "INDORE-BHOPAL", '03:00:00', 246, "INDB", '03:15:00', "BPL", '06:15:00'),
("RT010", "MUMBAI-GOA", '06:00:00', 588, "CSMT", '03:00:00', "VSG", '09:00:00'),
("RT023", "GOA-MUMBAI", '06:00:00', 588, "VSG", '12:15:00', "CSMT", '18:15:00'),
("RT011", "RAXAUL-HOWRAH", '17:50:00', 691, "RXL", '10:10:00', "HWH", '04:00:00'),
("RT024", "HOWRAH-RAXAUL", '17:50:00', 691, "HWH", '06:00:00', "RXL", '23:50:00');


```

```sql
insert into seats (seat_no,type) values (1,"LOWER"),(2,"MIDDLE"),(3,"UPPER"),(7,"S_LOWER"),(8,"S_UPPER"),(4,"LOWER"),(5,"MIDDLE"),(6,"UPPER"),(9,"LOWER"),(10,"MIDDLE"),(11,"UPPER"),(12,"LOWER"),(13,"MIDDLE"),(14,"UPPER"),(17,"LOWER"),(18,"MIDDLE"),(19,"UPPER"),(20,"LOWER"),(21,"MIDDLE"),(22,"UPPER"),(25,"LOWER"),(26,"MIDDLE"),(27,"UPPER"),(28,"LOWER"),(29,"MIDDLE"),(30,"UPPER"),(15,"S_LOWER"),(16,"S_UPPER"),(23,"S_LOWER"),(24,"S_UPPER");

```

```sql
INSERT INTO MAINTENANCE (maintain_no, maintain_type, maintain_date, coach_no) VALUES
("MNT001", "Mileage", "2023-10-15", "CN001"),
("MNT002", "Mileage", "2023-09-20", "CN002"),
("MNT003", "Mileage", "2023-11-05", "CN003"),
("MNT004", "Mileage", "2023-08-12", "CN004"),
("MNT005", "Mileage", "2023-10-30", "CN005"),
("MNT006", "Mileage", "2023-05-23", "CN006"),
("MNT007", "Mileage", "2023-11-10", "CN007"),
("MNT008", "Mileage", "2023-08-22", "CN008"),
("MNT009", "Mileage", "2023-10-05", "CN009"),
("MNT010", "Mileage", "2023-11-15", "CN010"),
("MNT011", "Mileage", "2023-09-10", "CN011"),
("MNT012", "Mileage", "2023-08-30", "CN012"),
("MNT013", "Mileage", "2023-10-20", "CN013"),
("MNT014", "Mileage", "2023-11-25", "CN014"),
("MNT015", "Mileage", "2023-09-15", "CN015"),
("MNT016", "Mileage", "2023-08-10", "CN016"),
("MNT017", "Mileage", "2023-10-25", "CN017"),
("MNT018", "Mileage", "2023-09-05", "CN018"),
("MNT019", "Mileage", "2023-07-20", "CN019"),
("MNT020", "Mileage", "2023-11-05", "CN020"),
("MNT021", "Mileage", "2023-10-30", "CN021"),
("MNT022", "Mileage", "2023-09-25", "CN022"),
("MNT023", "Mileage", "2023-08-22", "CN023"),
("MNT024", "Mileage", "2023-11-10", "CN024"),
("MNT025", "Mileage", "2023-10-05", "CN025"),
("MNT026", "Mileage", "2023-11-15", "CN026"),
("MNT027", "Mileage", "2023-09-10", "CN027"),
("MNT028", "Mileage", "2023-08-30", "CN028"),
("MNT029", "Mileage", "2023-10-20", "CN029"),
("MNT030", "Mileage", "2023-11-25", "CN030"),
("MNT031", "Mileage", "2023-09-15", "CN031"),
("MNT032", "Mileage", "2023-08-10", "CN032"),
("MNT033", "Mileage", "2023-10-25", "CN033"),
("MNT034", "Mileage", "2023-09-05", "CN034"),
("MNT035", "Mileage", "2023-07-20", "CN035"),
("MNT036", "Mileage", "2023-11-05", "CN036"),
("MNT037", "Mileage", "2023-10-30", "CN037"),
("MNT038", "Mileage", "2023-09-25", "CN038"),
("MNT039", "Mileage", "2023-08-22", "CN039"),
("MNT040", "Mileage", "2023-11-10", "CN040"),
("MNT041", "Mileage", "2023-10-05", "CN041"),
("MNT042", "Mileage", "2023-11-15", "CN042"),
("MNT043", "Mileage", "2023-09-10", "CN043"),
("MNT044", "Mileage", "2023-08-30", "CN044"),
("MNT045", "Mileage", "2023-10-20", "CN045"),
("MNT046", "Mileage", "2023-11-25", "CN046"),
("MNT047", "Mileage", "2023-09-15", "CN047"),
("MNT048", "Mileage", "2023-08-10", "CN048"),
("MNT049", "Mileage", "2023-10-25", "CN049"),
("MNT050", "Mileage", "2023-09-05", "CN050"),
("MNT051", "Mileage", "2023-07-20", "CN051"),
("MNT052", "Mileage", "2023-11-05", "CN052"),
("MNT053", "Mileage", "2023-10-30", "CN053"),
("MNT054", "Mileage", "2023-09-25", "CN054"),
("MNT055", "Mileage", "2023-08-22", "CN055"),
("MNT056", "Mileage", "2023-11-10", "CN056"),
("MNT057", "Mileage", "2023-10-05", "CN057"),
("MNT058", "Mileage", "2023-11-15", "CN058"),
("MNT059", "Mileage", "2023-09-10", "CN059"),
("MNT060", "Mileage", "2023-08-30", "CN060"),
("MNT061", "Mileage", "2023-10-20", "CN061"),
("MNT062", "Mileage", "2023-11-25", "CN062"),
("MNT063", "Mileage", "2023-09-15", "CN063"),
("MNT064", "Mileage", "2023-08-10", "CN064"),
("MNT065", "Mileage", "2023-10-25", "CN065"),
("MNT066", "Mileage", "2023-09-05", "CN066"),
("MNT067", "Mileage", "2023-07-20", "CN067"),
("MNT068", "Mileage", "2023-11-05", "CN068"),
("MNT069", "Mileage", "2023-10-30", "CN069"),
("MNT070", "Mileage", "2023-09-25", "CN070"),
("MNT071", "Mileage", "2023-08-22", "CN071"),
("MNT072", "Mileage", "2023-11-10", "CN072"),
("MNT073", "Mileage", "2023-10-05", "CN073"),
("MNT074", "Mileage", "2023-11-15", "CN074"),
("MNT075", "Mileage", "2023-09-10", "CN075"),
("MNT076", "Mileage", "2023-08-30", "CN076"),
("MNT077", "Mileage", "2023-10-20", "CN077"),
("MNT078", "Mileage", "2023-11-25", "CN078"),
("MNT079", "Mileage", "2023-09-15", "CN079"),
("MNT080", "Mileage", "2023-08-10", "CN080"),
("MNT081", "Mileage", "2023-10-25", "CN081"),
("MNT082", "Mileage", "2023-09-05", "CN082"),
("MNT083", "Mileage", "2023-07-20", "CN083"),
("MNT084", "Mileage", "2023-11-05", "CN084"),
("MNT085", "Mileage", "2023-10-30", "CN085"),
("MNT086", "Mileage", "2023-09-25", "CN086"),
("MNT087", "Mileage", "2023-08-22", "CN087"),
("MNT088", "Mileage", "2023-11-10", "CN088"),
("MNT089", "Mileage", "2023-10-05", "CN089"),
("MNT090", "Mileage", "2023-11-15", "CN090"),
("MNT091", "Mileage", "2023-08-30", "CN091"),
("MNT092", "Mileage", "2023-10-20", "CN092"),
("MNT093", "Mileage", "2023-11-25", "CN093"),
("MNT094", "Mileage", "2023-09-15", "CN094"),
("MNT095", "Mileage", "2023-08-10", "CN095"),
("MNT096", "Mileage", "2023-10-25", "CN096"),
("MNT097", "Mileage", "2023-09-05", "CN097"),
("MNT098", "Mileage", "2023-07-20", "CN098"),
("MNT099", "Mileage", "2023-11-05", "CN099"),
("MNT100", "Mileage", "2023-10-30", "CN100");


```

```sql
insert into train_schedule(route_no,train_no,station_code,Date,EAT,AAT,EDT,ADT) values
('RT001',22945,'CSMT','2023-10-14',NULL,NULL,'09:00:00','09:00:00'),
('RT001',22945,'JAM','2023-10-14','14:40:00','14:52:00',NULL,NULL),
('RT014',22946,'JAM','2023-10-14',NULL,NULL,'16:40:00','16:40:00'),
('RT014',22946,'CSMT','2023-10-14','22:20:00','22:20:00',NULL,NULL),
('RT001',22945,'CSMT','2023-10-10',NULL,NULL,'09:00:00','09:00:00'),
('RT001',22945,'JAM','2023-10-10','14:40:00','14:52:00',NULL,NULL),
('RT014',22946,'JAM','2023-10-10',NULL,NULL,'16:40:00','16:40:00'),
('RT014',22946,'CSMT','2023-10-10','22:20:00','22:20:00',NULL,NULL),
('RT001',22945,'CSMT','2023-10-12',NULL,NULL,'09:00:00','09:00:00'),
('RT001',22945,'JAM','2023-10-12','14:40:00','14:40:00',NULL,NULL),
('RT014',22946,'JAM','2023-10-12',NULL,NULL,'16:40:00','16:40:00'),
('RT014',22946,'CSMT','2023-10-12','22:20:00','22:20:00',NULL,NULL),
('RT002',14553,'NDLS','2023-12-25',NULL,NULL,'07:00:00','07:00:00'),
('RT002',14553,'UHL','2023-12-25','13:10:00','13:10:00',NULL,NULL),
('RT015',14552,'UHL','2023-12-25',NULL,NULL,'16:10:00','16:10:00'),
('RT015',14552,'NDLS','2023-12-25','22:20:00','22:20:00',NULL,NULL),
('RT003',11019,'SC','2023-12-28',NULL,NULL,'10:00:00','10:00:00'),
('RT003',11019,'VSKP','2023-12-28','18:30:00','18:30:00',NULL,NULL),
('RT016',11020,'VSKP','2023-12-28',NULL,NULL,'21:30:00','21:30:00'),
('RT016',11020,'SC','2024-12-29','00:20:00','00:20:00',NULL,NULL),
('RT004',22223,'CSMT','2024-01-03',NULL,NULL,'11:40:00','11:40:00'),
('RT004',22223,'SNSI','2024-01-03','17:00:00','17:00:00',NULL,NULL),
('RT017',22222,'SNSI','2024-01-03',NULL,NULL,'19:00:00','19:00:00'),
('RT017',22222,'CSMT','2024-01-04','00:20:00','00:20:00',NULL,NULL),
('RT005',11301,'CSMT','2024-01-15',NULL,NULL,'08:25:00','08:25:00'),
('RT005',11301,'SUR','2024-01-15','15:00:00','15:00:00',NULL,NULL),
('RT018',11302,'SUR','2024-01-15',NULL,NULL,'17:00:00','17:00:00'),
('RT018',11302,'CSMT','2024-01-15','23:35:00','23:35:00',NULL,NULL),
('RT006',12715,'BPL','2024-01-25',NULL,NULL,'20:15:00','20:15:00'),
('RT006',12715,'NDLS','2024-01-26','04:00:00','04:00:00',NULL,NULL),
('RT019',12716,'NDLS','2024-01-26',NULL,NULL,'06:00:00','06:00:00'),
('RT019',12716,'BPL','2024-01-26','13:45:00','13:45:00',NULL,NULL),
('RT007',19628,'LNL','2024-02-05',NULL,NULL,'02:15:00','02:15:00'),
('RT007',19628,'AII','2024-02-05','13:00:00','13:00:00',NULL,NULL),
('RT020',19627,'AII','2024-02-05',NULL,NULL,'16:00:00','16:00:00'),
('RT020',19627,'LNL','2024-02-06','02:45:00','02:45:00',NULL,NULL),
('RT008',17325,'DWR','2024-02-15',NULL,NULL,'05:00:00','05:00:00'),
('RT008',17325,'SBC','2024-02-15','10:00:00','10:00:00',NULL,NULL),
('RT021',17326,'SBC','2024-02-15',NULL,NULL,'12:00:00','12:00:00'),
('RT021',17326,'DWR','2024-02-15','17:00:00','17:00:00',NULL,NULL),
('RT009',18234,'BPL','2024-02-25',NULL,NULL,'21:15:00','21:15:00'),
('RT009',18234,'INDB','2024-02-26','00:15:00','00:15:00',NULL,NULL),
('RT022',18235,'INDB','2024-02-26',NULL,NULL,'03:15:00','03:15:00'),
('RT022',18235,'BPL','2024-02-26','06:15:00','06:15:00',NULL,NULL),
('RT010',10103,'CSMT','2024-03-05',NULL,NULL,'03:00:00','03:00:00'),
('RT010',10103,'VSG','2024-03-05','09:00:00','09:00:00',NULL,NULL),
('RT023',10102,'VSG','2024-03-05',NULL,NULL,'12:15:00','12:15:00'),
('RT023',10102,'CSMT','2024-03-05','18:15:00','18:15:00',NULL,NULL),
('RT011',13022,'RXL','2024-03-15',NULL,NULL,'10:10:00','10:10:00'),
('RT011',13022,'HWH','2024-03-16','04:00:00','04:00:00',NULL,NULL),
('RT024',13021,'HWH','2024-03-16',NULL,NULL,'06:00:00','06:00:00'),
('RT024',13021,'RXL','2024-03-16','23:50:00','23:50:00',NULL,NULL)

```

```sql
INSERT INTO coaches (coach_no, manufacturer, last_maintained, mileage) VALUES
('CN001', 'XYZ Company', '2023-10-15', 5000),
('CN002', 'ABC Corporation', '2023-09-20', 3000),
('CN003', 'LMN Industries', '2023-11-05', 2000),
('CN004', 'DEF Motors', '2023-08-12', 4500),
('CN005', 'PQR Ltd', '2023-10-30', 1000),
('CN006', 'UVW Inc', '2023-09-25', 3500),
('CN007', 'IJK Enterprises', '2023-11-10', 2500),
('CN008', 'OPQ Co', '2023-08-22', 4000),
('CN009', 'STU Corporation', '2023-10-05', 1500),
('CN010', 'EFG Industries', '2023-11-15', 3500),
('CN011', 'HIJ Motors', '2023-09-10', 4500),
('CN012', 'KLM Ltd', '2023-08-30', 2500),
('CN013', 'UVW Company', '2023-10-20', 500),
('CN014', 'RST Enterprises', '2023-11-25', 1000),
('CN015', 'ABC Motors', '2023-09-15', 3000),
('CN016', 'LMN Ltd', '2023-08-10', 2000),
('CN017', 'DEF Corporation', '2023-10-25', 4500),
('CN018', 'PQR Motors', '2023-09-05', 1000),
('CN019', 'XYZ Ltd', '2023-07-20', 5000),
('CN020', 'IJK Industries', '2023-11-05', 3000),
('CN021', 'OPQ Enterprises', '2023-10-30', 2500),
('CN022', 'EFG Co', '2023-09-25', 4000),
('CN023', 'HIJ Corporation', '2023-08-22', 1500),
('CN024', 'KLM Industries', '2023-11-10', 3500),
('CN025', 'STU Motors', '2023-10-05', 4500),
('CN026', 'RST Ltd', '2023-11-15', 2500),
('CN027', 'UVW Enterprises', '2023-09-10', 500),
('CN028', 'ABC Co', '2023-08-30', 1000),
('CN029', 'LMN Corporation', '2023-10-20', 3000),
('CN030', 'DEF Industries', '2023-11-25', 2000),
('CN031', 'PQR Motors', '2023-09-15', 5000),
('CN032', 'XYZ Ltd', '2023-08-10', 3000),
('CN033', 'IJK Industries', '2023-10-25', 1500),
('CN034', 'OPQ Enterprises', '2023-09-05', 3500),
('CN035', 'EFG Co', '2023-07-20', 4500),
('CN036', 'HIJ Corporation', '2023-11-05', 2500),
('CN037', 'KLM Industries', '2023-10-30', 500),
('CN038', 'STU Motors', '2023-09-25', 1000),
('CN039', 'RST Ltd', '2023-08-22', 3000),
('CN040', 'UVW Enterprises', '2023-11-10', 2000),
('CN041', 'ABC Co', '2023-10-05', 5000),
('CN042', 'LMN Corporation', '2023-11-15', 3000),
('CN043', 'DEF Industries', '2023-09-10', 1500),
('CN044', 'PQR Motors', '2023-08-30', 3500),
('CN045', 'XYZ Ltd', '2023-10-20', 4500),
('CN046', 'IJK Industries', '2023-11-25', 2500),
('CN047', 'OPQ Enterprises', '2023-09-15', 500),
('CN048', 'EFG Co', '2023-08-10', 1000),
('CN049', 'HIJ Corporation', '2023-10-25', 3000),
('CN050', 'KLM Industries', '2023-09-05', 2000),
('CN051', 'STU Motors', '2023-07-20', 5000),
('CN052', 'RST Ltd', '2023-11-15', 3000),
('CN053', 'UVW Enterprises', '2023-10-30', 1500),
('CN054', 'ABC Co', '2023-09-25', 4500),
('CN055', 'LMN Corporation', '2023-08-22', 2500),
('CN056', 'DEF Industries', '2023-11-10', 500),
('CN057', 'PQR Motors', '2023-10-05', 1000),
('CN058', 'XYZ Ltd', '2023-11-15', 3500),
('CN059', 'IJK Industries', '2023-09-10', 4500),
('CN060', 'OPQ Enterprises', '2023-08-30', 2000),
('CN061', 'EFG Co', '2023-10-20', 3000),
('CN062', 'HIJ Corporation', '2023-11-25', 500),
('CN063', 'KLM Industries', '2023-09-15', 1500),
('CN064', 'STU Motors', '2023-08-10', 4500),
('CN065', 'RST Ltd', '2023-10-25', 2500),
('CN066', 'UVW Enterprises', '2023-09-05', 5000),
('CN067', 'ABC Co', '2023-07-20', 3000),
('CN068', 'LMN Corporation', '2023-11-05', 1000),
('CN069', 'DEF Industries', '2023-10-30', 3500),
('CN070', 'PQR Motors', '2023-09-25', 2000),
('CN071', 'XYZ Ltd', '2023-08-22', 5000),
('CN072', 'IJK Industries', '2023-11-10', 3000),
('CN073', 'OPQ Enterprises', '2023-10-05', 1500),
('CN074', 'EFG Co', '2023-11-15', 4000),
('CN075', 'HIJ Corporation', '2023-09-10', 500),
('CN076', 'KLM Industries', '2023-08-30', 2500),
('CN077', 'STU Motors', '2023-10-20', 1000),
('CN078', 'RST Ltd', '2023-11-25', 3000),
('CN079', 'UVW Enterprises', '2023-09-15', 2000),
('CN080', 'ABC Co', '2023-08-10', 5000),
('CN081', 'LMN Corporation', '2023-10-25', 3500),
('CN082', 'DEF Industries', '2023-09-05', 1500),
('CN083', 'PQR Motors', '2023-07-20', 4000),
('CN084', 'XYZ Ltd', '2023-11-05', 500),
('CN085', 'IJK Industries', '2023-10-30', 2500),
('CN086', 'OPQ Enterprises', '2023-09-25', 3000),
('CN087', 'EFG Co', '2023-08-22', 1000),
('CN088', 'HIJ Corporation', '2023-11-10', 5000),
('CN089', 'KLM Industries', '2023-10-05', 3000),
('CN090', 'STU Motors', '2023-11-15', 2000),
('CN091', 'RST Ltd', '2023-08-30', 4500),
('CN092', 'UVW Enterprises', '2023-10-20', 1500),
('CN093', 'ABC Co', '2023-11-25', 5000),
('CN094', 'LMN Corporation', '2023-09-15', 3500),
('CN095', 'DEF Industries', '2023-08-10', 500),
('CN096', 'PQR Motors', '2023-10-25', 2500),
('CN097', 'XYZ Ltd', '2023-09-05', 3000),
('CN098', 'IJK Industries', '2023-07-20', 1000),
('CN099', 'OPQ Enterprises', '2023-11-05', 4500),
('CN100', 'EFG Co', '2023-10-30', 3000);

```

```sql
INSERT INTO train_coaches (train_no, coach_no, date_from) VALUES
(10102, 'CN001', '2023-11-14'),
(10102, 'CN002', '2023-11-14'),
(10102, 'CN003', '2023-11-14'),
(10102, 'CN004', '2023-11-14'),
(10102, 'CN005', '2023-11-14'),
(10102, 'CN006', '2023-11-14'),
(11301, 'CN007', '2023-11-14'),
(11301, 'CN008', '2023-11-14'),
(11301, 'CN009', '2023-11-14'),
(11301, 'CN010', '2023-11-14'),
(11301, 'CN011', '2023-11-14'),
(11301, 'CN012', '2023-11-14'),
(11019, 'CN013', '2023-11-14'),
(11019, 'CN014', '2023-11-14'),
(11019, 'CN015', '2023-11-14'),
(11019, 'CN016', '2023-11-14'),
(11019, 'CN017', '2023-11-14'),
(11019, 'CN018', '2023-11-14'),
(12715, 'CN019', '2023-11-14'),
(12715, 'CN020', '2023-11-14'),
(12715, 'CN021', '2023-11-14'),
(12715, 'CN022', '2023-11-14'),
(12715, 'CN023', '2023-11-14'),
(12715, 'CN024', '2023-11-14'),
(13021, 'CN025', '2023-11-14'),
(13021, 'CN026', '2023-11-14'),
(13021, 'CN027', '2023-11-14'),
(13021, 'CN028', '2023-11-14'),
(13021, 'CN029', '2023-11-14'),
(13021, 'CN030', '2023-11-14'),
(14552, 'CN031', '2023-11-14'),
(14552, 'CN032', '2023-11-14'),
(14552, 'CN033', '2023-11-14'),
(14552, 'CN034', '2023-11-14'),
(14552, 'CN035', '2023-11-14'),
(14552, 'CN036', '2023-11-14'),
(17325, 'CN037', '2023-11-14'),
(17325, 'CN038', '2023-11-14'),
(17325, 'CN039', '2023-11-14'),
(17325, 'CN040', '2023-11-14'),
(17325, 'CN041', '2023-11-14'),
(17325, 'CN042', '2023-11-14'),
(18234, 'CN043', '2023-11-14'),
(18234, 'CN044', '2023-11-14'),
(18234, 'CN045', '2023-11-14'),
(18234, 'CN046', '2023-11-14'),
(18234, 'CN047', '2023-11-14'),
(18234, 'CN048', '2023-11-14'),
(19627, 'CN049', '2023-11-14'),
(19627, 'CN050', '2023-11-14'),
(19627, 'CN051', '2023-11-14'),
(19627, 'CN052', '2023-11-14'),
(19627, 'CN053', '2023-11-14'),
(19627, 'CN054', '2023-11-14'),
(22222, 'CN055', '2023-11-14'),
(22222, 'CN056', '2023-11-14'),
(22222, 'CN057', '2023-11-14'),
(22222, 'CN058', '2023-11-14'),
(22222, 'CN059', '2023-11-14'),
(22222, 'CN060', '2023-11-14'),
(22945, 'CN061', '2023-11-14'),
(22945, 'CN062', '2023-11-14'),
(22945, 'CN063', '2023-11-14'),
(22945, 'CN064', '2023-11-14'),
(22945, 'CN065', '2023-11-14'),
(22945, 'CN066', '2023-11-14');

```

```sql
INSERT INTO active_coaches (coach_no, train_no) VALUES
('CN001', '10102'),
('CN002', '10102'),
('CN003', '10102'),
('CN004', '10102'),
('CN005', '10102'),
('CN006', '10102'),
('CN007', '11301'),
('CN008', '11301'),
('CN009', '11301'),
('CN010', '11301'),
('CN011', '11301'),
('CN012', '11301'),
('CN013', '11019'),
('CN014', '11019'),
('CN015', '11019'),
('CN016', '11019'),
('CN017', '11019'),
('CN018', '11019'),
('CN019', '12715'),
('CN020', '12715'),
('CN021', '12715'),
('CN022', '12715'),
('CN023', '12715'),
('CN024', '12715'),
('CN025', '13021'),
('CN026', '13021'),
('CN027', '13021'),
('CN028', '13021'),
('CN029', '13021'),
('CN030', '13021'),
('CN031', '14552'),
('CN032', '14552'),
('CN033', '14552'),
('CN034', '14552'),
('CN035', '14552'),
('CN036', '14552'),
('CN037', '17325'),
('CN038', '17325'),
('CN039', '17325'),
('CN040', '17325'),
('CN041', '17325'),
('CN042', '17325'),
('CN043', '18234'),
('CN044', '18234'),
('CN045', '18234'),
('CN046', '18234'),
('CN047', '18234'),
('CN048', '18234'),
('CN049', '19627'),
('CN050', '19627'),
('CN051', '19627'),
('CN052', '19627'),
('CN053', '19627'),
('CN054', '19627'),
('CN055', '22222'),
('CN056', '22222'),
('CN057', '22222'),
('CN058', '22222'),
('CN059', '22222'),
('CN060', '22222'),
('CN061', '22945'),
('CN062', '22945'),
('CN063', '22945'),
('CN064', '22945'),
('CN065', '22945'),
('CN066', '22945');

```

```sql
insert into staff_schedule(route_no,train_no,staff_no,remark,date,time) values
('RT001',22945,'S001','MAIN DRIVER','2023-10-10','09:00:00'),
('RT001',22945,'S002','CO-DRIVER','2023-10-10','09:00:00'),
('RT014',22946,'S001','MAIN DRIVER','2023-10-10','16:40:00'),
('RT014',22946,'S002','CO-DRIVER','2023-10-10','16:40:00'),
('RT001',22945,'S001','MAIN DRIVER','2023-10-14','09:00:00'),
('RT001',22945,'S002','CO-DRIVER','2023-10-14','09:00:00'),
('RT014',22946,'S001','MAIN DRIVER','2023-10-14','16:40:00'),
('RT014',22946,'S002','CO-DRIVER','2023-10-14','16:40:00'),
('RT001',22945,'S001','MAIN DRIVER','2023-10-12','09:00:00'),
('RT001',22945,'S002','CO-DRIVER','2023-10-12','09:00:00'),
('RT014',22946,'S001','MAIN DRIVER','2023-10-12','16:40:00'),
('RT014',22946,'S002','CO-DRIVER','2023-10-12','16:40:00'),
('RT002',14553,'S003','MAIN DRIVER','2023-12-25','07:00:00'),
('RT002',14553,'S004','CO-DRIVER','2023-12-25','07:00:00'),
('RT015',14552,'S003','MAIN DRIVER','2023-12-25','16:10:00'),
('RT015',14552,'S004','CO-DRIVER','2023-12-25','16:10:00'),
('RT003',11019,'S005','MAIN DRIVER','2023-12-28','10:00:00'),
('RT003',11019,'S006','CO-DRIVER','2023-12-28','10:00:00'),
('RT016',11020,'S005','MAIN DRIVER','2023-12-28','21:30:00'),
('RT016',11020,'S006','CO-DRIVER','2023-12-28','21:30:00'),
('RT004',22223,'S007','MAIN DRIVER','2024-01-03','11:40:00'),
('RT004',22223,'S008','CO-DRIVER','2024-01-03','11:40:00'),
('RT017',22222,'S007','MAIN DRIVER','2024-01-03','19:00:00'),
('RT017',22222,'S008','CO-DRIVER','2024-01-03','19:00:00'),
('RT005',11301,'S009','MAIN DRIVER','2024-01-15','08:25:00'),
('RT005',11301,'S010','CO-DRIVER','2024-01-15','08:25:00'),
('RT018',11302,'S009','MAIN DRIVER','2024-01-15','17:00:00'),
('RT018',11302,'S010','CO-DRIVER','2024-01-15','17:00:00'),
('RT006',12715,'S011','MAIN DRIVER','2024-01-25','20:15:00'),
('RT006',12715,'S012','CO-DRIVER','2024-01-25','20:15:00'),
('RT019',12716,'S011','MAIN DRIVER','2024-01-26','06:00:00'),
('RT019',12716,'S012','CO-DRIVER','2024-01-26','06:00:00'),
('RT007',19628,'S013','MAIN DRIVER','2024-02-05','02:15:00'),
('RT007',19628,'S014','CO-DRIVER','2024-02-05','02:15:00'),
('RT020',19627,'S013','MAIN DRIVER','2024-02-05','16:00:00'),
('RT020',19627,'S014','CO-DRIVER','2024-02-05','16:00:00'),
('RT008',17325,'S015','MAIN DRIVER','2024-02-15','05:00:00'),
('RT008',17325,'S016','CO-DRIVER','2024-02-15','05:00:00'),
('RT021',17326,'S015','CO-DRIVER','2024-02-15','12:00:00'),
('RT021',17326,'S016','MAIN DRIVER','2024-02-15','12:00:00'),
('RT009',18234,'S017','MAIN DRIVER','2024-02-25','21:15:00'),
('RT009',18234,'S018','CO-DRIVER','2024-02-25','21:15:00'),
('RT022',18235,'S017','CO-DRIVER','2024-02-26','03:15:00'),
('RT022',18235,'S018','MAIN DRIVER','2024-02-26','03:15:00'),
('RT010',10103,'S019','MAIN DRIVER','2024-03-05','03:00:00'),
('RT010',10103,'S020','CO-DRIVER','2024-03-05','03:00:00'),
('RT023',10102,'S019','MAIN DRIVER','2024-03-05','12:15:00'),
('RT023',10102,'S020','CO-DRIVER','2024-03-05','12:15:00'),
('RT011',13022,'S021','MAIN DRIVER','2024-03-15','10:10:00'),
('RT011',13022,'S022','CO-DRIVER','2024-03-15','10:10:00'),
('RT024',13021,'S021','MAIN DRIVER','2024-03-16','06:00:00'),
('RT024',13021,'S022','CO-DRIVER','2024-03-16','06:00:00');

```

```sql
INSERT INTO staffs (staff_no, staff_name, contact_no, residence_city) VALUES
('S001', 'Rahul Sharma', '+91 12345 67890', 'Delhi'),
('S002', 'Priya Singh', '+91 98765 43210', 'Mumbai'),
('S003', 'Ajay Verma', '+91 11122 23333', 'Bengaluru'),
('S004', 'Anjali Khanna', '+91 44455 56666', 'Chennai'),
('S005', 'Vikram Patel', '+91 77788 89999', 'Kolkata'),
('S006', 'Neha Gupta', '+91 99900 01111', 'Hyderabad'),
('S007', 'Raj Malhotra', '+91 22233 34444', 'Pune'),
('S008', 'Kavita Tiwari', '+91 55566 67777', 'Jaipur'),
('S009', 'Arjun Reddy', '+91 88899 00000', 'Ahmedabad'),
('S010', 'Mahima Desai', '+91 66677 88888', 'Kochi'),
('S011', 'Prateek Mehta', '+91 33344 45555', 'Chandigarh'),
('S012', 'Swati Sharma', '+91 00011 12222', 'Lucknow'),
('S013', 'Rahul Kumar', '+91 11122 23333', 'Goa'),
('S014', 'Kriti Verma', '+91 22233 34444', 'Indore'),
('S015', 'Rohit Singh', '+91 33344 45555', 'Jaipur'),
('S016', 'Manisha Reddy', '+91 99999 88888', 'Hyderabad'),
('S017', 'Neeraj Bhatia', '+91 77777 66666', 'Mumbai'),
('S018', 'Meera Sharma', '+91 55555 44444', 'Delhi'),
('S019', 'Vinay Kapoor', '+91 33333 22222', 'Bengaluru'),
('S020', 'Pooja Singh', '+91 11111 00000', 'Kolkata'),
('S021', 'Suresh Patel', '+91 88888 99999', 'Chennai'),
('S022', 'Shikha Verma', '+91 66666 88888', 'Pune'),
('S023', 'Rohan Khanna', '+91 44444 77777', 'Jaipur'),
('S024', 'Divya Jain', '+91 22222 66666', 'Lucknow'),
('S025', 'Rajesh Agarwal', '+91 11111 55555', 'Goa'),
('S026', 'Ananya Das', '+91 99999 44444', 'Indore'),
('S027', 'Varun Malhotra', '+91 77777 33333', 'Jaipur'),
('S028', 'Asha Singh', '+91 55555 22222', 'Hyderabad'),
('S029', 'Ravi Patel', '+91 33333 11111', 'Mumbai'),
('S030', 'Priyanka Reddy', '+91 22222 00000', 'Delhi'),
('S031', 'Aditya Sinha', '+91 00000 99999', 'Bengaluru'),
('S032', 'Deepa Chawla', '+91 88888 88888', 'Kolkata'),
('S033', 'Vivek Kapoor', '+91 66666 77777', 'Chennai'),
('S034', 'Shivani Sharma', '+91 44444 66666', 'Pune'),
('S035', 'Nikhil Verma', '+91 22222 55555', 'Jaipur'),
('S036', 'Sweta Mehra', '+91 11111 44444', 'Lucknow'),
('S037', 'Aman Kumar', '+91 99999 33333', 'Goa'),
('S038', 'Megha Sen', '+91 77777 22222', 'Indore'),
('S039', 'Rohan Singh', '+91 55555 11111', 'Jaipur'),
('S040', 'Ashwini Reddy', '+91 33333 00000', 'Hyderabad'),
('S041', 'Kunal Sharma', '+91 22222 99999', 'Mumbai'),
('S042', 'Anjali Suri', '+91 11111 88888', 'Delhi'),
('S043', 'Vikas Malhotra', '+91 00000 77777', 'Bengaluru'),
('S044', 'Aditi Verma', '+91 88888 66666', 'Kolkata'),
('S045', 'Pranav Kapoor', '+91 66666 55555', 'Chennai'),
('S046', 'Simran Khanna', '+91 44444 44444', 'Pune'),
('S047', 'Arvind Singh', '+91 22222 33333', 'Jaipur'),
('S048', 'Anushka Tiwari', '+91 11111 22222', 'Lucknow'),
('S049', 'Rajat Kumar', '+91 99999 11111', 'Goa'),
('S050', 'Meghna Reddy', '+91 77777 00000', 'Indore'),
('S051', 'Sandeep Mehta', '+91 55555 99999', 'Jaipur'),
('S052', 'Ankita Sharma', '+91 33333 88888', 'Hyderabad'),
('S053', 'Alok Patel', '+91 22222 77777', 'Mumbai'),
('S054', 'Priya Jain', '+91 11111 66666', 'Delhi'),
('S055', 'Abhay Gupta', '+91 00000 55555', 'Bengaluru'),
('S056', 'Swati Singh', '+91 88888 44444', 'Kolkata'),
('S057', 'Rajiv Malhotra', '+91 66666 33333', 'Chennai'),
('S058', 'Ritika Verma', '+91 44444 22222', 'Pune'),
('S059', 'Kunal Bhatia', '+91 22222 11111', 'Jaipur'),
('S060', 'Shweta Reddy', '+91 11111 00000', 'Lucknow'),
('S061', 'Sarthak Singh', '+91 99999 99999', 'Goa'),
('S062', 'Harini Suri', '+91 77777 88888', 'Indore'),
('S063', 'Arnav Sharma', '+91 55555 77777', 'Jaipur'),
('S064', 'Anushka Sen', '+91 33333 66666', 'Hyderabad'),
('S065', 'Ram Kapoor', '+91 22222 55555', 'Mumbai'),
('S066', 'Leela Verma', '+91 11111 44444', 'Delhi'),
('S067', 'Kabir Singh', '+91 00000 33333', 'Bengaluru'),
('S068', 'Ritu Tiwari', '+91 88888 22222', 'Kolkata'),
('S069', 'Manoj Gupta', '+91 66666 11111', 'Chennai'),
('S070', 'Ashwini Sharma', '+91 44444 00000', 'Pune'),
('S071', 'Shreya Khanna', '+91 22222 99999', 'Jaipur'),
('S072', 'Soham Patel', '+91 11111 88888', 'Lucknow'),
('S073', 'Ankita Mehta', '+91 99999 77777', 'Goa'),
('S074', 'Vishal Singh', '+91 77777 66666', 'Indore'),
('S075', 'Neha Reddy', '+91 55555 55555', 'Jaipur'),
('S076', 'Rahul Kumar', '+91 33333 44444', 'Hyderabad'),
('S077', 'Sanjana Verma', '+91 22222 33333', 'Mumbai'),
('S078', 'Kartik Suri', '+91 11111 22222', 'Delhi'),
('S079', 'Nisha Malhotra', '+91 00000 11111', 'Bengaluru'),
('S080', 'Arjun Sinha', '+91 88888 00000', 'Kolkata'),
('S081', 'Aditi Bhatia', '+91 66666 99999', 'Chennai'),
('S082', 'Aman Sharma', '+91 44444 88888', 'Pune'),
('S083', 'Sakshi Kapoor', '+91 33333 77777', 'Jaipur'),
('S084', 'Abhay Mehra', '+91 22222 66666', 'Lucknow'),
('S085', 'Ananya Singh', '+91 11111 55555', 'Goa'),
('S086', 'Alok Malhotra', '+91 99999 44444', 'Indore'),
('S087', 'Manvi Reddy', '+91 77777 33333', 'Jaipur'),
('S088', 'Raghav Kumar', '+91 55555 22222', 'Hyderabad'),
('S089', 'Akanksha Mehta', '+91 44444 11111', 'Mumbai'),
('S090', 'Pranav Verma', '+91 33333 00000', 'Delhi'),
('S091', 'Simran Singh', '+91 22222 99999', 'Bengaluru'),
('S092', 'Sidharth Tiwari', '+91 11111 88888', 'Kolkata'),
('S093', 'Anika Patel', '+91 88888 77777', 'Chennai'),
('S094', 'Soham Sharma', '+91 66666 66666', 'Pune'),
('S095', 'Avni Singh', '+91 55555 55555', 'Jaipur'),
('S096', 'Kabir Reddy', '+91 44444 44444', 'Lucknow'),
('S097', 'Alisha Gupta', '+91 33333 33333', 'Goa'),
('S098', 'Aniket Malhotra', '+91 22222 22222', 'Indore'),
('S099', 'Tanvi Sinha', '+91 11111 11111', 'Jaipur'),
('S100', 'Arnav Sharma', '+91 99999 99999', 'Hyderabad');
```

```sql
INSERT INTO tickets (ticket_no, train_no, status, passenger_name, age, passenger_type, board_stn, drop_stn, date_of_journey, booking_date, fare, discount, travel_agent_id, agent_comm)VALUES
('TKT001', 22945, 'confirmed', 'Priya Patel', 28, 'adult', 'CSMT', 'JAM', '2023-12-15', '2023-11-01', 1200, 0, 'TA001', 120),
('TKT002', 22946, 'confirmed', 'Rajesh Kumar', 35, 'adult', 'JAM', 'CSMT', '2023-12-18', '2023-11-03', 1500, 0, 'TA002', 150),
('TKT003', 14552, 'pending', 'Neha Sharma', 22, 'adult', 'UHL', 'NDLS', '2023-12-20', '2023-11-15', 1100, 0, 'TA003', 110),
('TKT004', 14553, 'confirmed', 'Aryan Singh', 45, 'adult', 'NDLS', 'UHL', '2023-12-25', '2023-11-08', 1350, 0, 'TA001', 135),
('TKT005', 11019, 'confirmed', 'Ananya Das', 30, 'adult', 'SC', 'VSKP', '2023-12-28', '2023-12-20', 1250, 0, 'TA004', 125),
('TKT006', 11020, 'confirmed', 'Ravi Verma', 32, 'adult', 'VSKP', 'SC', '2023-12-30', '2023-11-20', 1400, 0, 'TA002', 140),
('TKT007', 22223, 'pending', 'Sanjay Singh', 40, 'adult', 'CSMT', 'SNSI', '2024-01-03', '2023-12-25', 1150, 0, NULL, NULL),
('TKT008', 22222, 'confirmed', 'Kavita Reddy', 27, 'adult', 'SNSI', 'CSMT', '2024-01-10', '2023-12-01', 1300, 0, 'TA003', 130),
('TKT009', 11301, 'confirmed', 'Neha Patel', 8, 'child', 'CSMT', 'SUR', '2024-01-15', '2023-12-05', 1550, 388, 'TA004', 155),
('TKT010', 11302, 'confirmed', 'Rakesh Verma', 65, 'senior citizen', 'SUR', 'CSMT', '2024-01-20', '2023-12-10', 1650, 165, 'TA001', 165),
('TKT011', 12715, 'confirmed', 'Priyanka Singh', 31, 'adult', 'BPL', 'NDLS', '2024-01-25', '2023-12-15', 1200, 0, 'TA002', 120),
('TKT012', 12716, 'pending', 'Rahul Sharma', 70, 'senior citizen', 'NDLS', 'BPL', '2024-02-01', '2023-12-20', 1250, 125, NULL, NULL),
('TKT013', 19628, 'confirmed', 'Kirti Das', 20, 'adult', 'LNL', 'AII', '2024-02-05', '2023-12-25', 1100, 275, 'TA003', 110),
('TKT014', 19627, 'confirmed', 'Ajay Mehta', 58, 'adult', 'AII', 'LNL', '2024-02-10', '2024-01-01', 1450, 145, 'TA004', 145),
('TKT015', 17325, 'confirmed', 'Anu Singh', 10, 'child', 'DWR', 'SBC', '2024-02-15', '2024-01-05', 1300, 325, 'TA001', 130),
('TKT016', 17326, 'pending', 'Ritu Reddy', 26, 'adult', 'SBC', 'DWR', '2024-02-20', '2024-01-10', 1350, 0, NULL, NULL),
('TKT017', 18234, 'confirmed', 'Viren Kapoor', 68, 'senior citizen', 'BPL', 'INDB', '2024-02-25', '2024-01-15', 140),
('TKT018', 18235, 'confirmed', 'Ayesha Verma', 55, 'adult', 'INDB', 'BPL', '2024-03-01', '2024-01-20', 1250, 125, 'TA004', 125),
('TKT019', 10103, 'confirmed', 'Sameer Singh', 45, 'adult', 'CSMT', 'VSG', '2024-03-05', '2024-01-25', 1200, 120, 'TA001', 120),
('TKT020', 10102, 'pending', 'Ria Sharma', 17, 'adult', 'VSG', 'CSMT', '2024-03-10', '2024-02-01', 1150, 287, NULL, NULL),
('TKT021', 13022, 'confirmed', 'Arjun Das', 30, 'adult', 'RXL', 'HWH', '2024-03-15', '2024-01-05', 1300, 0, 'TA003', 130),
('TKT022', 13021, 'confirmed', 'Pooja Patel', 62, 'senior citizen', 'HWH', 'RXL', '2024-03-20', '2024-02-10', 1350, 135, 'TA004', 135),
('TKT023', 13021, 'confirmed', 'Rohan Reddy', 28, 'adult', 'HWH', 'RXL', '2024-03-25', '2024-02-15', 1400, 0, 'TA001', 140),
('TKT024', 14552, 'pending', 'Divya Kapoor', 40, 'adult', 'NDLS', 'UHL', '2024-03-30', '2024-02-20', 1450, 0, NULL, NULL),
('TKT025', 19628, 'confirmed', 'Karan Verma', 70, 'senior citizen', 'LNL', 'AII', '2024-04-01', '2024-02-25', 1200, 120, 'TA003', 120),
('TKT026', 12716, 'confirmed', 'Tanvi Singh', 26, 'adult', 'NDLS', 'BPL', '2024-04-05', '2024-03-01', 1250, 0, 'TA004', 125),
('TKT027', 13022, 'confirmed', 'Anil Sharma', 59, 'adult', 'RXL', 'HWH', '2024-04-10', '2024-03-05', 1300, 130, 'TA001', 130),
('TKT028', 12715, 'pending', 'Meera Das', 8, 'child', 'BPL', 'NDLS', '2024-04-15', '2024-03-10', 1350, 338, NULL, NULL),
('TKT029', 13022, 'confirmed', 'Aditi Reddy', 65, 'senior citizen', 'RXL', 'HWH', '2024-04-20', '2024-03-15', 1400, 140, 'TA003', 140),
('TKT030', 10102, 'confirmed', 'Suresh Patel', 31, 'adult', 'VSG', 'CSMT', '2024-04-25', '2024-03-20', 1450, 0, 'TA004', 145),
('TKT031', 22945, 'confirmed', 'Priya Patel', 28, 'adult', 'CSMT', 'JAM', '2023-11-15', '2023-10-01', 1200, 0, 'TA001', 120),
('TKT032', 22946, 'confirmed', 'Rajesh Kumar', 35, 'adult', 'JAM', 'CSMT', '2023-11-18', '2023-10-03', 1500, 0, 'TA002', 150),
('TKT033', 14552, 'pending', 'Neha Sharma', 22, 'adult', 'UHL', 'NDLS', '2023-09-20', '2023-08-15', 1100, 0, 'TA003', 110),
('TKT034', 14553, 'confirmed', 'Aryan Singh', 45, 'adult', 'NDLS', 'UHL', '2023-10-25', '2023-09-08', 1350, 0, 'TA001', 135),
('TKT035', 11019, 'confirmed', 'Ananya Das', 30, 'adult', 'SC', 'VSKP', '2023-10-28', '2023-09-20', 1250, 0, 'TA004', 125),
('TKT036', 11020, 'confirmed', 'Ravi Verma', 32, 'adult', 'VSKP', 'SC', '2023-10-30', '2023-09-20', 1400, 0, 'TA002', 140),
('TKT037', 22223, 'pending', 'Sanjay Singh', 40, 'adult', 'CSMT', 'SNSI', '2023-12-03', '2023-11-25', 1150, 0, NULL, NULL),
('TKT038', 22222, 'confirmed', 'Kavita Reddy', 27, 'adult', 'SNSI', 'CSMT', '2024-01-10', '2023-12-01', 1300, 0, 'TA003', 130),
('TKT039', 11301, 'confirmed', 'Neha Patel', 8, 'child', 'CSMT', 'SUR', '2023-12-15', '2023-11-05', 1550, 388, 'TA004', 155),
('TKT040', 11302, 'confirmed', 'Rakesh Verma', 65, 'senior citizen', 'SUR', 'CSMT', '2024-01-20', '2023-12-10', 1650, 165, 'TA001', 165),
('TKT041', 12715, 'confirmed', 'Priyanka Singh', 31, 'adult', 'BPL', 'NDLS', '2023-12-25', '2023-11-15', 1200, 0, 'TA002', 120),
('TKT042', 12716, 'pending', 'Rahul Sharma', 70, 'senior citizen', 'NDLS', 'BPL', '2024-01-01', '2023-11-20', 1250, 125, NULL, NULL),
('TKT043', 19628, 'confirmed', 'Kirti Das', 20, 'adult', 'LNL', 'AII', '2023-12-05', '2023-11-25', 1100, 275, 'TA003', 110),
('TKT044', 19627, 'confirmed', 'Ajay Mehta', 58, 'adult', 'AII', 'LNL', '2024-01-10', '2023-12-01', 1450, 145, 'TA004', 145),
('TKT045', 17325, 'confirmed', 'Anu Singh', 10, 'child', 'DWR', 'SBC', '2024-01-15', '2023-12-05', 1300, 325, 'TA001', 130),
('TKT046', 17326, 'pending', 'Ritu Reddy', 26, 'adult', 'SBC', 'DWR', '2024-01-20', '2023-12-10', 1350, 0, NULL, NULL),
('TKT047', 18234, 'confirmed', 'Viren Kapoor', 68, 'senior citizen', 'BPL', 'INDB', '2024-01-25', '2023-12-15', 1400, 140, 'TA003', 140),
('TKT048', 18235, 'confirmed', 'Ayesha Verma', 55, 'adult', 'INDB', 'BPL', '2024-02-01', '2023-12-20', 1250, 125, 'TA004', 125),
('TKT049', 10103, 'confirmed', 'Sameer Singh', 45, 'adult', 'CSMT', 'VSG', '2024-02-05', '2023-12-25', 1200, 120, 'TA001', 120),
('TKT050', 10102, 'pending', 'Ria Sharma', 17, 'adult', 'VSG', 'CSMT', '2024-02-10', '2024-01-01', 1150, 287, NULL, NULL),
('TKT051', 13022, 'confirmed', 'Arjun Das', 30, 'adult', 'RXL', 'HWH', '2024-02-15', '2024-01-05', 1300, 0, 'TA003', 130),
('TKT052', 13021, 'confirmed', 'Pooja Patel', 62, 'senior citizen', 'HWH', 'RXL', '2024-02-20', '2024-01-10', 1350, 135, 'TA004', 135),
('TKT053', 13021, 'confirmed', 'Rohan Reddy', 28, 'adult', 'HWH', 'RXL', '2024-02-25', '2024-01-15', 1400, 0, 'TA001', 140),
('TKT054', 14552, 'pending', 'Divya Kapoor', 40, 'adult', 'NDLS', 'UHL', '2024-03-01', '2024-01-20', 1450, 0, NULL, NULL),
('TKT055', 19628, 'confirmed', 'Karan Verma', 70, 'senior citizen', 'LNL', 'AII', '2024-03-05', '2024-01-25', 1200, 120, 'TA003', 120),
('TKT056', 12716, 'confirmed', 'Tanvi Singh', 26, 'adult', 'NDLS', 'BPL', '2024-03-10', '2024-02-01', 1250, 0, 'TA004', 125),
('TKT057', 13022, 'confirmed', 'Anil Sharma', 59, 'adult', 'RXL', 'HWH', '2024-03-15', '2024-02-05', 1300, 130, 'TA001', 130),
('TKT058', 12715, 'pending', 'Meera Das', 8, 'child', 'BPL', 'NDLS', '2024-03-20', '2024-02-10', 1350, 338, NULL, NULL),
('TKT059', 13022, 'confirmed', 'Aditi Reddy', 65, 'senior citizen', 'RXL', 'HWH', '2024-03-25', '2024-02-15', 1400, 140, 'TA003', 140),
('TKT060', 10102, 'confirmed', 'Suresh Patel', 31, 'adult', 'VSG', 'CSMT', '2024-03-30', '2024-02-20', 1450, 0, 'TA004', 145),
('TKT061', 16505, 'pending', 'Ankit Kumar', 25, 'adult', 'DWR', 'SBC', '2023-10-10', '2023-10-08', 2100, 0, NULL, NULL),
('TKT062', 16505, 'pending', 'Rishi Kumar', 24, 'adult', 'DWR', 'SBC', '2023-10-14', '2023-10-09', 2100, 0, NULL, NULL),
('TKT063', 18505, 'pending', 'Yash Kumar', 20, 'adult', 'DWR', 'SBC', '2023-10-14', '2023-10-09', 2100, 0, NULL, NULL),
('TKT064', 18505, 'pending', 'Shashi Ranjan', 23, 'adult', 'DWR', 'SBC', '2023-10-09', '2023-10-09', 2100, 0, NULL, NULL),
('TKT065', 18505, 'pending', 'Shashi Ranjan', 23, 'adult', 'DWR', 'SBC', '2023-10-15', '2023-10-09', 2100, 0, NULL, NULL),
('TKT066', 18505, 'confirmed', 'Shashi Ranjan', 23, 'adult', 'DWR', 'SBC', '2023-10-06', '2023-10-05', 2100, 0, NULL, NULL),
('TKT067', 18505, 'confirmed', 'Rajiv Ranjan', 23, 'adult', 'DWR', 'SBC', '2023-10-09', '2023-10-09', 2100, 0, NULL, NULL),
('TKT068', 18505, 'confirmed', 'Ritesh Yeole', 23, 'adult', 'DWR', 'SBC', '2023-10-11', '2023-10-09', 2100, 0, NULL, NULL);

```

```sql

```
## Part 2 
 - [Shashi](https://github.com/ranjanshashi9471/ca105_assignment/shashi_23112036.md)
