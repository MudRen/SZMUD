// Code of ShenZhou
// pingtai.c �ͱ��ϵ�ƽ̨
// qfy July 13, 1996

inherit ROOM;

void create()
{
        set("short", "ƽ̨");
        set("long", @LONG
ƽ̨��ʯ�ϡ���ڣ����������֮�ԣ��������������С��ʯ��(shike)
������һ�������ʯ��ѳɵĴ��(grave)����ر���ɽ�ȣ�����������ռ
�����ƣ�����ѳɴ˷ص�ǰ������ȫ�ţ������ǳ���
LONG
        );

	set("item_desc",([
            "shike" : "����ħ������ܼ��޵�����£������˹��\n"
	   	      "�غ���Ⱥ�����֣��������������౯�򣡡�\n",
	    "grave" : "��������ʯ��ѳɡ�\n"
        ]));


	set("cost", 1);
        setup();
}

void init()
{
	this_player()->delete_temp("marks/��");
	add_action("do_climb", "climb");
	add_action("do_move", "move");
	add_action("do_put", "put");
}

int do_climb(string arg)
{
	object me = this_player();
	me->delete_temp("diao_winner");

	if ( !arg )
	   return notify_fail( "ʲô��\n" );

	if ( arg != "down" ) 
	   return notify_fail( "�㲻�����Ƕ�����\n" );

   	message_vision("$N���㲢�ã�С����������ͱ�����ȥ��\n", me);
   	me->move(__DIR__"qiaobi1");
	message("vision", me->name()+"��ƽ̨������������\n", environment(me), me);

	return 1;
}

int do_move(string arg)
{
        object sword, diao, me = this_player();

        if ( !arg || arg != "stone" )
           return notify_fail( "ʲô��\n" );

     if ( !me->query_temp("marks/��") ) {
      if ( !objectp(present("xuantie jian", me)) && !objectp(present("xuantie jian", environment(me))) ) {
	me->set_temp("marks/��", 1);

	if ( !me->query_temp("diao_winner") ) {
	   message_vision("$N��ͼ������ϵ�ʯ��Ὺ��\n", me);

	   if ( !me->query_temp("fought_diao") ) {
	      message_vision("�����á�������������һ�ɾ������������ԭ������Ѹ��������ֹ$N��ʯ��\n", me);
              if ( !present("shen diao", environment(me) ) ) {
		diao = new(__DIR__"npc/shendiao");
              	diao->move(environment(me));
	      }
	      diao = present( "shen diao", environment(me) ); 
              COMBAT_D->do_attack(diao, me, query_temp("weapon") );
              me->set_temp("fighter", 1);
              diao->fight_ob(me);
              me->fight_ob(diao);
	      me->set_temp("fought_diao", 1);
	      call_out("observe",1,me,diao);
	   }
	   else return notify_fail("�㳢���ƿ���һ����ʯ�飬ȴ�������в�����ʯ���Ȼ������\n");
	}
	else {
	   message_vision("$N��ʯ��Ὺ������һ�ԡ�\n", me);
	   sword = new("/clone/unique/xuantie-jian");
           if (!sword) 
	   return notify_fail("�㷢��ԭ����������������������֪�����к���ͼ��\n");
	   sword->move(environment(me));
	   CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ�������ؽ���", me->query("name")));
	   message_vision("�����ԭ�������һ��������������۵ĳ�����\n", me);
	   message_vision("$N�������𳤽���ֻ���߱�Ǻ��һ�����ֵ��£���ʯ��һ�������Ľ���\n", me);
	   message_vision("ԭ���ǽ�����֮�������߶೤��һ�ѽ����������Բ����߰�ʮ�\n", me);
	   message_vision("���Ե�һ��ʯƬ��д�ţ����ؽ��޷棬���ɲ�������ʮ��ǰ��֮�������¡���\n", me);
	   me->set_temp("marks/��", 1);
	   me->delete_temp("diao_winner");			
	   me->delete_temp("fought_diao");
	   me->delete_temp("marks/��");
	}
     }
     else return notify_fail( "�����������ؽ��������ؽ����ڵ��ϣ��αض��һ�٣�\n");
   } 
   else return notify_fail( "����ȡ�������ؽ��ˣ�\n" ); 

     return 1;
}

int observe(object me, object diao)
{
	object ob;

	if( me->is_fighting() && me->query_temp("marks/��") ) {
            call_out("observe",1,me,diao);
            return 1;
        }

	if( diao->query("qi")*2 <= diao->query("max_qi") ) {
	     me->remove_enemy(diao);
	     diao->remove_enemy(me);
             me->set_temp("diao_winner", 1);
             message_vision("����$N���ͷ��ʾ�������������ص�һ���ʯŲ����\n", me);
	     message_vision("��������$N��ʯ�����ű�������뿪ƽ̨��\n", me);
	     destruct(diao);
        }

	return 1;
}

int do_put(string arg)
{
        string sword, what;
        object ob, obj, me = this_player();

        if( !arg || sscanf(arg, "%s in %s", sword, what)!=2 )
                return notify_fail("�����ʽ: put <��Ʒ> in <��Ʒ>��\n");

	if ( what != "grave" ){
	printf("��Ҫ�Ѷ����������?\n"); 
	return 1;
	}

	if (!(ob=present(sword,me))){
	printf("������û������������\n"); 
	return 1;
	}

	if (ob->query("id")!="xuantie jian"){
	printf("�㲻�ܰ�" + ob->name() + "�Ž�ʯ���������\n"); 
	return 1;
	}

//	printf("%s , %s ", sword, what); return 1;

        message_vision("$N��" + ob->name() + "�Ż�ʯ���������\n", me);
        destruct(ob);

	message_vision("ͻȻ$N����һ������˵������û�뵽����С�Ӿ�����˳�Ϣ���ϵô˴�������\n", me);
	message_vision("$Nһ����ͷ��������������ɿ���վ��һ�����ۿͣ��ұ�һֻ����տ���Ҳ��\n", me);
	me->set_temp("marks/yangguo", 1);
	obj = load_object("/kungfu/class/gumu/yangguo");
	obj->move("/d/taishan/pingtai");
	if ( me->query("shen") >= -100000 ) {      
		message("vision","�����"+me->name()+"������˵�˼��仰��\n", environment(me), ({me})); 	
          }
          else {	
          	message_vision( "�������$N���ã�һ����̾����ƮȻ��ɽ��ȥ��\n", me );
		destruct(obj);
          }	
	return 1;
}
