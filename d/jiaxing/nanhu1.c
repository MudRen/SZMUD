// Code of ShenZhou
// Room: /d/quanzhou/nanhu1.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�����Ϻ�");
	set("long", @LONG
�������̲������Ϻ������ϼ�ֻ�������ε������ϵ��οͺ�
��¥Ů������Ц����ˮ���û�д��Ƕɲ���ȥ�ġ�����֪��˭��
���׶���һЩľ׮��׮��Ǳ��ˮ��֮��һ����ĵط�����ʹ�ǲ���
�Ṧ��������ȥҲ����ˮ��Ư�����ӡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"yanyu",
		"east" : __DIR__"zhoushan",
                "northwest" : __DIR__ "nanhu",
	]));

	set("outdoors", "quanzhou");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

