//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�й��");
	set("long", @LONG
����������й�λ���ų����룬�ǿ���ʱ��Ԫ�����������ϸĽ��ġ�
��֮����ṹΪ���Σ�����Ъɽ������������ã���ΪЪɽ���������ݶ�����
����ʹ�֮��¥״�������������û������ߣ����߼��ߡ����ڹ������������
�������������Ͼ����Ϊ����ʱ����֮��������һ��ߴ�Ծ������ɣ�
������ǣ�Ǭ¡������Ϊ���������
LONG
	);
	set("cost", 2);
 
	set("exits", ([
                "east" : __DIR__"zhaojing",
                "west" : __DIR__"yanxiang",
                "north" : __DIR__"jingji",
                "south" : __DIR__"yuweng",
        ]));
	
	
	setup();
	replace_program(ROOM);
}