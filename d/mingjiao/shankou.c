// Code of ShenZhou
// room: /mingjiao/shankou.c

inherit ROOM;

void create()
{
        set("short", "������ɽ��");
        set("long", @LONG
�˴��������̸���֮�أ�����������ɽ�ƿ����������Ƭ�ķ��ݱ���
�ܶ档���̴��������ѽ����꣬�������й����Ѳ�֮�����������˳�����
֮Ϊ��ħ�̡���
LONG );

        set("exits", ([
                "north"     : __DIR__"damen",
                "southdown" : __DIR__"shanlu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
