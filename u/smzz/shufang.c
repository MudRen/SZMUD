inherit ROOM;
void create()

{
set("short","ɳ��ի");
set("long",
"һ�����ܴ���鷿,Ψһ�����İ������һ̨������˵���.�����ӵ��鼮\n" 
"���治֪����û��ʲôϡ���ؼ�\n" 
);
set("exits",([ "south":"u/smzz/room",]));
set("cost", 0);
setup();
replace_program(ROOM); 
}
