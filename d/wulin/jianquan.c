// room /d/wulin/jianquan.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
�˴����ǽ���Ȫ�ˣ�����ʯ���м���Ȫˮ��������ʳ������ഫ����
��λ���ָ����ڴ˱��䣬������͸��ʯ���γɴ�Ȫˮ�������Ȫˮ�峺��
�����߽���֮Ч��������ʿ��ϣ��һƷ��Ȫ֮����
LONG
        );

        set("exits", ([
                "west" : __DIR__"shanlu",
        ]));     

        set("resource/water",1);
        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
