// Code of ShenZhou
// road: /zhongnan/dating.c
// Xuanyuan

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
��������õļ�Ϊ�򵥣�����ľ�κ��������ӷ��������У���ǽ����
��С�����ϵ���һ��С��¯��Ʈ�������������̴���һ����ζ����ֻ����
��ζ��Ũ�����壬��������һ��ƮƮȻ�ĸо������е����ϲ��˼�֦����
������յ����λεġ�����������һ��С�ſ�ͨ�����ã����෽������
�����ߵ���
LONG);

	set("exits",([ "west" : __DIR__"zoudao4",
		"south" : __DIR__"houtang",
		"east" : __DIR__"zoudao3",
		"north" : __DIR__"zoudao2",
	]));
	set("objects",([
                "/kungfu/class/gumu/longnu" : 1
	]));
	set("cost",1);
        "/clone/board/gumu_b"->foo();
	 setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object obj;

        myfam = (mapping)me->query("family");

        if ( objectp(obj=present("xiao longnu", environment(me))) && living(obj) && !wizardp(me) ) {
           if ( (!myfam || myfam["family_name"] != "��Ĺ��") && (dir == "east" || dir == "west") )
                return notify_fail("С��Ů˵���������صأ�"+RANK_D->query_respect(me)+"ֹ����\n");

           if ( myfam && myfam["family_name"] != "��Ĺ��" && (dir == "south" || dir == "east" || dir == "west"))
                return notify_fail("С��Ů˵���������صأ�"+RANK_D->query_respect(me)+"ֹ����\n");
        
	   if ( myfam && myfam["master_name"] == "��Ī��" && dir == "east" )
                return notify_fail("С��Ů˵�����㻹����ʦ�㱾����ȡ��Ů�ľ��ɡ�\n");
        }

        return ::valid_leave(me, dir);

}
