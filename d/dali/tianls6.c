//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "��Ԫ��");
        set("long", @LONG
�˴���������ɮ��������֮�ء�һ����̴ľ���������ڵ��У���������ߣ�
��ʮ���㣬�������Σ�����ׯ�ϡ�����վ�˰���������ߵĻ�����ա��Ŀ������
����ڹ��߻Ұ�������ζ�̱ǣ�һƬ�ž���������Ψ��һ���ͼ�Ħ���ͭ��
LONG
        );
        set("no_clean_up", 0);
        set("cost", 3);
        set("exits", ([
		"northwest" : __DIR__"tianls9.c",
        "south" : __DIR__"tianls5.c",		]));
setup();
        replace_program(ROOM);
}


























