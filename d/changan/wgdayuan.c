//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","��ݴ�Ժ");
	set("long",@LONG
��վ����ݵĽ������У��������Ż�ɫ��ϸɰ��һȺ��ʮ�����С������
��Ŭ���Ĳ����ţ����ϻ���λ��ͷģ�������ھ������ǵĴ��󡣻��и�С����
�ں��š�ǰ���ж�ǽ(wall)��ǽ�ĺ�����ǳ����ǵĶķ���
LONG
	);
	set("exits",([
		"east" : __DIR__"wuguan",
	]));

	setup();
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;

        if( arg=="wall")
        {
                if (me->query_skill("dodge",1)<100)
                    write("����ͼ����ǽ���ķ��Ǳ�ȥ��������������ȥ��\n");
                else {
                    write("������Ծ����ǽ��\n");
                    message("vision",
                             me->name() + "һ����Ծ����ǽ�����ķ�ȥ�ˡ�\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"dufang");
                    message("vision",
                             me->name() + "����ݴ�ԺԾ�˹�����\n",
                             environment(me), ({me}) );
                }
                return 1;
           
        }
}

