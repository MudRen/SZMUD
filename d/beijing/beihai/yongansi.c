//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������£���ʷ�Ѿ����ƾ��ˡ��������±��ϾͿ��Ե������������������
һ��ʯ�ţ�������ʯ�ţ������Ӱ���ɽ���ųǵ�ͨ����
LONG
	);
	set("cost", 2);
	
      
	 
	set("exits", ([
                "northup" : __DIR__"baita",
                "south" : __DIR__"yonganqiao",
                "west" : __DIR__"yuexin",
                "northeast" : __DIR__"zhizhu",
                ]));
	
	
	setup();
	replace_program(ROOM);
}
