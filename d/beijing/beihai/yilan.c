//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������뱱������ͤ��ˮ���������ϲ�����֮�����£��γ�һ������ʽ
֮����������ʯ�Ҷ�����ʯ����ͤ������������ͨ���������ɣ��к����á�
д��ʯ�ҡ���᰾��ᡢ����¥��һ�����ͤ��С����ͤ�ȡ���¥�������ƺ�
������������Ϊ����¥������Ϊ�����󣬷ֱ���Ϊ�����õ���ڡ��Ǵ�¥
����հ��������̲����н�ɽ����һ��֮ʤ��
LONG
	);
	set("cost", 2);
	 
	set("exits", ([
                "southup" : __DIR__"baita",
                "northeast" : __DIR__"dukou2",
                "southwest" : __DIR__"yuegu",
                "southeast" : __DIR__"shiqiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
