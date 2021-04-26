// Code of ShenZhou
// /d/zhongnan/bingqifang.c ������
// sdong

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������������ı�������ǽ�ϸ���������೤�����̽����񽣺ͷ�����
LONG
		  );

		  set("exits", ([
					 "south" : __DIR__"yinwutin",
		  ]));

        set("objects", ([
                __DIR__"obj/changjian" : 3,
                __DIR__"obj/duanjian" : 1,
                __DIR__"obj/zhujian" : 1,
                "/clone/weapon/fuchen" : 4,
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

