// Filename:   /d/jueqinggu/shishi2.c ʯ��2
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","ʯ��");
		  set("long",@LONG
����һ�䲻���ʯ�ң�����ֻ�ڷ�һ��ľ�ƴ��������Ϸ���Щ����
�����ߣ�ǽ�Ϲ���Щ��ɫ��������ʯ�ҵ������Ǵ�����ʱ��ʱ��������
�Ĵ�������
LONG);
		  set("exits",([ 
			  "west" : __DIR__"dating",
			 ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}