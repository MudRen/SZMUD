//Cracked by Roath
// Room: biaoju �ھִ�Ժ
// Ssy

inherit ROOM;

void create()
{
        set("short", "�ھִ�Ժ");
        set("long", @LONG
��������ʤ�ھֵĴ�Ժ����ʯ������һ����Ⱦ��Ժ�����˲��ٻ��ݣ�һƬ��
����������Ժ��������γ������ĶԱȡ���ʤ�ھֵ�����ͷ���˳ơ���ǹ�޵С�
������ͨ�;�����Ժ�ڴ����ھ�����
LONG
        );

        set("exits", ([
                "south" : __DIR__"wusheng",
        ]));

        set("objects", ([
                __DIR__"npc/wangwutong" : 1,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

