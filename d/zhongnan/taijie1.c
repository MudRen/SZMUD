// Code of ShenZhou
// Room: /d/zhongnan/taijie1.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
        set("short", "̨��");
        set("long", @LONG
�����������ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ����̨��̨���Ͼ����ο�
�����룬���꣬�ɺ׵����ޣ���̬���涯�ˡ���̨���з��Ÿ����˸ߵ���ͭ����¯��
ǰ����Ÿ���̨����λ����������Ӱݡ�����ǰ��������
LONG
        );

        set("exits", ([
                "south" : __DIR__"gate1",
                "northup" : __DIR__"sanqing",
        ]));

        set("outdoors", "zhongnan");
        set("objects",([
                __DIR__"npc/xiang-ke" : 1,
        ]));
        set("cost", 2);
        setup();
        replace_program(ROOM);
}


