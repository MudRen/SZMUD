// July 31,2000
// Code by April
// /gumu/mudao2.c

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
                "west" : __DIR__"dating",
                "north" : __DIR__"shishi_m1",
                "east" : __DIR__"mudao3",
                "south" : __FILE__,
                 ])
                          );
        create_door("north", "ľ��", "south");

        set("cost",1);

        setup();
        
        replace_program(ROOM);
}
