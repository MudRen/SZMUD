// Code of ShenZhou
// road: /zhongnan/nyuqinshi.c

inherit ROOM;

void create()
{
        set("short","Ů�᷿");

        set("long",@LONG
�����Ů�᷿����Ȼȫ��̵�Ů���Ӳ��࣬�����徻ɢ���ﲻ����
ָ���£�Ҳ�ܲ�����ü�������е������Ҳ��õĴ�ͬС�죬����ľ��
��һ�����ӣ����ϵı����۵��������룬���һ���һ�������ζ����
LONG);
                       
        set("exits",([ "south" : __DIR__"liangong2",
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

        if ( dir == "west" || dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }

        return ::valid_leave(me, dir);
}



