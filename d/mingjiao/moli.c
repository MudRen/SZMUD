// Code of ShenZhou
// room: /mingjiao/moli.c

inherit ROOM;

void create()
{
        set("short", "Ħ��ɽ");
        set("long", @LONG
ɽ����һƬ��ѹѹ������֮�У������������ա���Χ��ľ����������
��ͥ���󶼽в������֡�������Լ��������֮����ʱԶʱ������֮����
����ζϮ���������˷������¡�����ʮ����������������Ϲۿ�ʱ����
Ȼ���ּ���������Ҷ�еİ׹ǣ�
LONG );
        set("exits", ([
                "south" : __DIR__"suibei",
        ]));

	set("objects",([
		__DIR__"obj/xiaohuangshi" : 2,
]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 3);
	set("cost", 3);

        setup();
        replace_program(ROOM);
}