// July 31,2000
// Code by April
// /gumu/mudao15.c

inherit ROOM;

void create()
{
        set("short","Ĺ��");

        set("long",@LONG
����ɭɭ��Ĺ����Ҳ��֪����ͨ���Ķ��ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ��Ĺ������Զһ�����
�������ˡ�Ĺ����ͷ�ƺ���Щ����������
LONG);

         set("exits",([ 
                "west" : __DIR__"mudao16",
                "east" : __DIR__"dating",
                "south" : __DIR__"fengfang",
                "north" : __DIR__"shuifang",
                 ]));

		 create_door("north", "ľ��", "south");
		 set("cost",1);
		 setup();
}
