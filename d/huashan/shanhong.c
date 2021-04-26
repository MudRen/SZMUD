// Code of ShenZhou
// ɽ���ٲ�
// qfy 7/7/1996

inherit ROOM;

void create()
{
        set("short", "ɽ���ٲ�");
        set("long", @LONG
ת��һ��ɽϿ��ˮ�����������ֻ��ɽ���һ��������Ƶ��ٲ���к
���£�����һ��Ϫ������ʤ�������ļ��쳣��ˮ��Ю����֦ʯ�飬ת�۱�
���ò�֪ȥ��Ϫ��(river)��������һ���ʯ(stone)��ˮ���ɽ����Ĺ�
ˮ�����ɣ�εΪ��ۡ���ɽ���Ƶ����ң��������о��⣬���Ǳ������ĺá�
LONG
        );
        
        set("exits", ([ /* sizeof() == 1 */
                "southwest":__DIR__"shaluo",
        ]));

        set("item_desc",([
            "stone" : "һ��޴����ʯ���������ر�ɽ���͸����ɡ�\n",
            "river" : "ɽˮ���ٲ�����Ϫ���������쳣�ļ���\n",
        ]));
        
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        set("cost", 4);
        setup();
}

void init()
{
        object me = this_player();

        if ( interactive(me) && me->query("huashan/job_pending") ) {
                me->set_temp("hz_job/shanhong", 1);
        }

        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "stone" )
             return notify_fail( "ʲô��\n");

	if (me->is_busy())
	     return notify_fail("����æ���أ�\n");	

        message_vision("$N��������ʯ����ȥ��\n", me);

        if ( me->query_skill("dodge",1) <= 20 ) {
             message_vision("$N˫��һ��ˮ��ɽ���������ҡ�һϣ�����վ�ȡ�һ����㷢��\n", me);
             message_vision("һ���Һ�����ɽ������Ӱ�����ˡ�\n", me);
             me->receive_wound("qi", me->query("max_qi")+100, "��ɽ��������");
        }

        if ( me->query_skill("dodge",1) > 20 && me->query_skill("dodge",1) <= 30 ) {
             message_vision("$N˫��һ��ˮ��ɽ���������ҡ�һϣ�����վ�ȡ�ֻ����������\n", me);
             message_vision("���������򰶱ߡ�\n", me);
             me->unconcious();
        }

        if ( me->query_skill("dodge",1) > 30 && me->query_skill("dodge",1) <= 40 ) {
             message_vision("$N˫��һ��ˮ���㱻ɽ������ҡ�һϣ�����վ�ȡ�ֻ����������\n", me);
             message_vision("���������򰶱ߡ�$N������ʮ��ƣ�룬�úú���Ϣ�ˡ�\n", me);
             me->receive_damage("qi", 100, "����͸֧��������");
        }
        
        if ( me->query_skill("dodge",1) > 40 && me->query_skill("dodge",1) <= 50 ) {
             message_vision("$N˫��һ��ˮ�����׮վ�ȡ�����һ�����е����������������\n", me);
             message_vision("�ꡣֻ������Ծ�ذ��ϡ�\n", me);
        }

        if ( me->query_skill("dodge",1) > 50 ) {
             me->move(__DIR__"dashi");
             message("vision", me->name() + "�����ɰ������˹�����\n",environment(me), ({me}) );
        }

        return 1;
} 
