// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "�̲���");
	set("long", @LONG
�ƹ���ͬʯ����һ��ĺ��̷壬��һ����Ө��͸�������ĳ�ˮ���ص������ۻ�
Ȫ��һΪ��Ȫ��һΪ��Ȫ�����Գ�ˮ��ů�������ļ����ԣ���ˮ���ؼѣ�����������
�κ���Ȫ������������Ǻ������֣�������ɫ���������ܻ������д��������Ѵ�
������ꡣ����˵�����пɿ˰ٶ��ġ������ޡ����֡���������ԼԼ��һ�����ᣬ��
�濿�������Ĵ���һ�����δ�ʯ��
LONG
	);
	 set("exits", ([
                "southwest" : __DIR__"hanbi",
                "east" : __DIR__"tingyu",
                "north" : __DIR__"jingshe",
                "west" : __DIR__"xuetang",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
