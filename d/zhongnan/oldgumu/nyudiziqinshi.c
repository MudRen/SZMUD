// Code of ShenZhou
// road: /zhongnan/nyudiziqinshi.c

inherit ROOM;

void create()
{
        set("short", "������Ϣ��");

        set("long",@LONG
��춹�Ĺ��ֻ��Ů���ӣ�Ĺ��Ҳֻ�д�һ����Ϣ�ҡ����м���ʯ����
����Щ���죬��ܣ��ͦ�Ǹɾ��ġ�ǽ���и�С���ӣ�������˸�ͭ����һ
Щ��֬���и��������ڴ�硣�ӱ���С�ų�ȥ��һ���ߵ���
LONG);

        set("exits",([ "north" : __DIR__"zoudao4",

                      ])
           );
  	set("cost",0);
        set("sleep_room", 1);
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;


        inv = all_inventory(me);

        if ( dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }
        return ::valid_leave(me, dir);
}

