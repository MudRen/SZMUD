// July 31,2000
// Code by April
// /gumu/mudao1.c

inherit ROOM;

void create()
{
        set("short","Ĺ��");

        set("long",@LONG
���������ɭɭ��Ĺ����Ҳ��֪����ͨ���Ķ��ġ�Ĺ��Ĺ�ֻ������
����Ĺ������Զһ����Ϳ������ˡ�Ĺ����ͷ�ƺ���Щ����������
LONG);

         set("exits",([ 
               // "west" : __FILE__,
                "north" : __DIR__"dating",
              //  "east" : __FILE__,
                "out" : __DIR__"gumu",
				]));

          set("cost",1);
		  setup();
		  replace_program(ROOM);
}
