// Code of ShenZhou
// Room: /d/zhongnan/taijie.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
        set("short", "̨��");
        set("long", @LONG
��������ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ����̨��̨���Ͼ���
�ο������룬���꣬�ɺ׵����ޣ���̬���涯�ˡ���̨���з��Ÿ����˸ߵ�
��ͭ����¯��ǰ����Ÿ���̨����λ����������Ӱݡ�����ǰ���Ǻ�
LONG
                  );

                  set("exits", ([
                                         "southup" : __DIR__"chanshen",
                                         "northup" : __DIR__"haodian",
					 "right" : __DIR__"wusezhai",
                  ]));

        set("outdoors", "zhongnan");
        set("objects",([
                __DIR__"npc/xiang-ke" : 1,
        ]));
        set("cost", 2);
        setup();
}

