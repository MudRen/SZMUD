// Code of ShenZhou
// room: /mingjiao/luyuhe.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һת���ֳ�һ���ݹ��ϱ��ĵĺ����������Ǻ�ˮҲ�����������
���ף�һȺȺС�㴩��������������ľ��ʹ���ˮ��Ҳ�в���֦Ҷ��ˮƮ
����ӳ�������Ӷ����ֱ���֮ɫ�����ߵ�·ʮ����Ţ����غ�ˮ����֮�ʡ�
LONG );

        set("exits", ([
                "westup" : __DIR__"daqing",
                "north" : __DIR__"yanrandu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}