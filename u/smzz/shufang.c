inherit ROOM;
void create()

{
set("short","沙仕斋");
set("long",
"一个不很大的书房,唯一豪华的摆设就是一台联想个人电脑.满屋子的书籍\n" 
"里面不知道有没有什么稀世秘籍\n" 
);
set("exits",([ "south":"u/smzz/room",]));
set("cost", 0);
setup();
replace_program(ROOM); 
}
