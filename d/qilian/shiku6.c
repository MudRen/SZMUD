// Code of ShenZhou
inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG
����ĵ���������κʱ����������ò���ݡ�üĿ���ʡ������ƽ��
��С��������ׯ�ϴ���ķ��������鵭��������Ʈ���г��ķ��졢��
�ʹ�������ʿ��
LONG);

  set("exits", ([ 
  "east" : __DIR__"dtongdao3",
]));

	set("cost", 2);
  setup();
  replace_program(ROOM);
}

