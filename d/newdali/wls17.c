// Code of ShenZhou
// Room: /dali/wls16.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; w; s; n; ne; w; sw; n; #9, ne; sw; nw; e; s; w; sw; 16: n; w;

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
���������ϴ������ڵ�����ɽ����������᫣���������������û�е�·��ֻ��
һЩ���˺Ͳ�ҩ���߳�����С�������������Ӻڣ�������·�����Ҿ�����������
�������Ժܴ�һ�ж���û���ˡ��������߽�������Ҳû��ȥ���㻹��С��Ϊ�á�
���ǣ���ս����ͷ��ֲ����ϵ��巽���ˣ�
LONG );

	set("exits", ([
		"southeast" : __DIR__"wls1",
		"northeast" : __DIR__"wls1",
		"southwest" : __DIR__"wls1",
		"northwest" : __DIR__"wls1",
		"south"     : __DIR__"wls16",
		"north"     : __DIR__"wls1",
		"west"      : __DIR__"wls",
                "east"      : __DIR__"wls1",
	]));

	set("cost", 3);
        set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_drop", "drop");
}

int do_drop(object ob)
{
	write("�㲻�ܰ�����������������ݴ����Ҳ����ġ�\n");
	return 1;
}