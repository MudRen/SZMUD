//Cracked by sleep
// /d/wuguan/zhbshi.c װ����
// sdong

inherit ROOM;

void create()
{
        set("short", "װ����");
        set("long", @LONG
��������ݵ�װ���ң�ǽ�ϸ������˸��ָ�����������
LONG
		  );

		  set("exits", ([
					 "south" : __DIR__"qianting",
		  ]));

        set("objects", ([
                "/clone/weapon/zhujian" : 3,
                "/clone/weapon/mudao" : 3,
                "/clone/weapon/fuchen" : 3,
                "/clone/weapon/feibiao" : 1,
                "/clone/weapon/tiezhang" : 1,
                "/clone/weapon/tiegun" : 1,
                "/clone/weapon/tiebang" : 1,
                "/clone/weapon/stone" : 1,
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

