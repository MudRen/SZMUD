// Code of ShenZhou
// changle/zoulang1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������������������ڱ����ܶ����լ�ˡ������Ǽ����
��Ĳ񷿣����и�СС��ͤ�ӡ�һЩ�ճ������İ��ھ����ע����
ÿ���ˡ�
LONG );

        set("exits", ([
		"south" : __DIR__"cldating",
		"north" : __DIR__"clzoulang2",
		"west" :  __DIR__"clchaifang",
		"east" :  __DIR__"clbajiaoting",
        ]));

        set("cost", 0);

        setup();

        replace_program(ROOM);
}

