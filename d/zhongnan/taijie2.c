// Code of ShenZhou
// Room: /d/zhongnan/taijie2.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
		  set("short", "̨��");
		  set("long", @LONG
��������ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ����̨��̨���Ͼ���
�ο������룬���꣬�ɺ׵����ޣ���̬���涯�ˡ���̨���з��Ÿ����˸ߵ�
��ͭ����¯��ǰ����Ÿ���̨����λ����������Ӱݡ�����ǰ���ǳ����
LONG
		  );

		  set("exits", ([
					 "south" : __DIR__"dadian",
					 "northup" : __DIR__"chanshen",
		  ]));

        set("outdoors", "zhongnan");
        set("objects",([
                __DIR__"npc/xiang-ke" : 1,
		//"/clone/npc/qiu": 1,
        ]));
        set("cost", 2);
        setup();
		call_other("/clone/board/quanzhen_b","???");
}

