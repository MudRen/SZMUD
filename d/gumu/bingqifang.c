// Code of ShenZhou
// /d/gumu/bingqifang.c ������
// Lara

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǹ�Ĺ�ɵı�������ǽ�ϸ���������೤�����̽����񽣺ͷ�����
LONG
		  );

		  set("exits", ([
		  "east" : __DIR__"mudao16",
		  ]));

        set("objects", ([
                "/clone/weapon/changjian" : 3,
                "/clone/weapon/duanjian" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/fuchen" : 2,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
                if ((string)inv[i]->query("skill_type")=="blade") j++;
        }
        
        if ( j == 1 ) me->set_temp("marks/��", 1);
        if ( j > 1 ) return notify_fail("����ô��˽���㲻�ܴ��߳���һ�ѱ�����\n");

        return ::valid_leave(me, dir);
}

