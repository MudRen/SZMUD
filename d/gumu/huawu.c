// Code by April
// /gumu/huawu.c

inherit ROOM;

void create()
{
        set("short","��������");

        set("long",@LONG
��һ����������ԣ�����������һ�������磬�����֦��ɷ�Ǻÿ���
�������񴹸ǣ�������Ȼ��ɵ�һ���������ݡ�����������������������
����һƬ���ģ�ֻ��Ȫ����������˼���ȷ�Ǹ��Ϻõ��������ڡ�
LONG);

        set("exits", ([
        "out" : __DIR__"milin10",
                      ]));
		set("resource/water", 1);	

		set("cost",1);
		set("outdoors", "gumu");
        setup();
        replace_program(ROOM);
}
