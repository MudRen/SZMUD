//Cracked by Roath
// xiakedao/dadong.c
// modified by aln 5 / 98
// modified by sdong to forbid bringing laba zhou out, 6/99
// Modified by xQin to forbid players return to xkd to ask laba zhou 7/00

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��ǰ��Ȼ����������ɽ������������ڷ���һ�ٶ������ӣ���
Χ���ţ�����������������ʹ�����ȥ����������������������
�������ž޴��ʯ�Ρ�������λ������������磬�����Ǿ޷���д��
ɽˮ�����ƻֺ롣
LONG );

      set("exits", ([
      	"south" : __DIR__"yongdao3",
//	"enter" : __DIR__"yongdao10", 
      ]));

	set("cost", 0);
	set("objects", ([ 
	    __DIR__ + "npc/sipu" : 1,
      ]));
	set("food_count", 5);
	set_temp("opened", 0);
    //call_other("/clone/board/xkd_b", "???");
	setup();
    "/clone/board/xkd_b"->foo();
    "/clone/board/xkd_b"->save();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object *inv;
        int found, i;
        
        myfam = (mapping)me->query("family");


		  inv = all_inventory(me);
		  for (i=0; i<sizeof(inv); i++) {
					 if ( inv[i]->is_container() && present("zhou", inv[i]) )  found = 1;
		  }

		  if ( present("zhou", me) || found )
					 return notify_fail("�������������ٳ�ȥ��\n");

		  return ::valid_leave(me, dir);
}
void init()
{
        object me = this_player();

        if ((me->query("combat_exp") > 10000) && (wizhood(me) == "(player)"))
	{	
	message_vision(" �����Ը���������͵�Ե���Ծ�������ū������һ�̡�\n", me);
	message_vision("$N���������ı�����������ת�ۼ�������󳵸�ǰ��\n", this_player());
	message_vision("���͹��˹���˵���������أ�������ڣ���\n",me); 
	me->move("/d/xiakedao/shatan3");


}
}