//Cracked by Roath
// xiakedao/xiuxi.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
ɽ����ֻ����һ��С�͵ƣ��ƹ�谵�����Ŵ������ſ���������
�����Ժ��������š�һ�ſ�����Ĵ������ţ���������ˣ��Ϳ�����
����˯��(sleep)��ǽ�Ϻ�������һ��С����(tiaozi)��
LONG );

      set("exits", ([
      	"east" : __DIR__"yongdao4",
      ]));
	set("sleep_room", 1);
	set("no_fight", 1);

	set("item_desc",([
	    "tiaozi" : 
"������֣�������С�˳����˳�˯ʱ͵�������������мǣ����й���
����ǧ��С�ġ�\n",
	]));

	set("cost", 0);
	setup();
}
