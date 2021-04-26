// Code of ShenZhou
// Room: /city/zuixianlou2.c
// YZC 1995/12/04 
// Modified by xQin 5/00
// Modified by Sure 9/2000

inherit ROOM;
inherit F_DEALER;

void create()
{
        set("name", "����¥");
        set("short", "����¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ���
���ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ�����Ŀ�������
������һ�غ�ˮ���̲������������ǳ�ɽ���룬��������Կ�������ȫ���İ�¹
��Ժ�ĺ�ͥ��ǽ�Ϲ��ż۸�����(paizi)������Ŀ���ʱʱ����ϲ����䡣
LONG
        );

        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ƣ�����ɫ���ȡ�\n",
        ]));

        set("objects", ([
                __DIR__"npc/xian" : 1,
                "/clone/npc/guidao" : 1,
                "/kungfu/class/shenlong/pang" : 1,
        ]));
/*
        set("uni_objects", ({
                "/clone/npc/guidao",
                "/kungfu/class/shenlong/pang",
        }));
*/
        set("exits", ([
                "down" : __DIR__"zuixianlou",
                "east" : __DIR__"datang",
        ]));

        set("cost", 1);

        setup();
}
