// Code of ShenZhou
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG
�������һ��ʯ�ߣ�����������񡢸����ڶ࣬���ж�������Ϊģ��Ī
�����������������º͵ķ𡢷�����������������̬�����������׳��������
��ʿ�����Ź����ıڻ��͵��ŵĽ������������桢�����Ӱ����Ϊ������гͳ
һ�����壬չʾ��������Զ���⾳��
LONG);
set("exits", ([
  "west" : __DIR__"dtongdao5",
]));
  replace_program(ROOM);
	set("cost", 2);
  setup();
}

