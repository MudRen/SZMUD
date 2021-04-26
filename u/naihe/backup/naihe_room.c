//                ��׼��������ʾ��                                   |
// �κεķ��ӣ�ȫ�¸İ棡/u/naihe/naihe_room.c
// by naihe  2002-05-15
// ������ȫ���Լ�д�Ĵ��룡ֻ���Ǹ�������ʱ���ڵĴ��룬
// ���ǡ���ʱ��Ϯ����������װ��˫��call_out�ģ�������

#include <ansi.h>
inherit ROOM;

string look_left();
int t_armor,t_note,t_movebed,t_listen,t_find,t_findok,lose_things,gem_take,
lose_things=20;
// ��ֵlose_things������ÿִ��һ����Ҫ���پ������ĺ���ʱ�����������ĳֵ���Դ�ֵ��������
// �������˼���ǣ�����Ҫ���پ������Ǿͽ����������� ��ʮ��֮һ ����ʱ������
string msg,path,last_finder,rdpath;

void create()
{
	set("short",BLU"�嶥С��"NOR);
	set("long",@LONG
������ӿյ����ģ�ֻ���Ŷ���ǽ�ߵ�һֻ�����ڷ��Ż谵�Ĺ⣬��ʱ��ʱ
������˸�š����°ڷ���һ��ľ����bed�� ����������ص�����һЩ�鼮���·���
���Ӻ���ͷ����ͷ���ϻ�����һ��Ƕ��Сľ�������Ƭ��photo���� ��������Ȼ
�������Ĵ���������ĳЩ����˵�������Ϣ��������ĳ�ֺܵ�����Զ��̾Ϣ��һ
�㣬�ܹ�����ƽ����˼���š���ǰ���ڵ��Ϻ�ǽ�ߵĻҳ���֩����ȫ�������ˣ�
����ĳ����������⡪��������������Щ���Ծ�������˵��������
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up","1");
	set("item_desc",([
	    "left": (: look_left :) ,
	    "right":"�ұ�ǽ�ϸɾ�ƽ����ʲô�ر�ĵط�Ҳ����������\n",
	    "front":"ǰ��ǽ�����и�С���������ҡ���ţ���������ﴵ������ȴһ��о�Ҳû�С�\n",
	    "rear":"����ػ�ͷ���˿������ʲôҲû�С�̫�����˰ա�\n",
            "photo":"����һ��������͵���ͷ����д��Ƭ�����м��ֿɰ���\n��Ƭ��ǩ��һ���ʲݵ��֣���find������֪����ʲô��˼��\n",
	    "bed":"һ��Сľ�����ƺ��ܾ�û��˯���ˡ���ͷ������Լ���Կ����и�С���ӣ�sm_note����һ�ǡ�\n",
	    "sm_note":"ԭ����ֻ��һ��ֽ���Ѿ��ܾ��ˡ��ܶ�ط������������ֻ������϶�������д�ţ�
"YEL"������֪����������������ܣ���������ô�������Ѫ��Ѱ�ҡ���Ҳ�����Ҳ���
�����κΡ����ɡ����ǣ�������ô�죿���������ң���Ӧ�á�������������������"NOR"
����Ĵ��ҳ��֪��ô�ĸ�˺���ˣ�Ҳ��֪����˭д�ġ�\n",
	]));
	set("exits",([
	    "out":"/d/huashan/fengding",
//	    "dc":"/clone/misc/naihe/dc_dating",
//          "west":"/u/spark/spark_room",
	]));

	setup();
	call_other("/clone/board/naihe_b","???");

}

void init()
{
	add_action("do_note","note");
        add_action("do_sleep","sleep");
	add_action("do_armor","armor");
	add_action("do_listen","listen");
	if(this_player()->query("id")!="naihe") add_action("do_nomore","more");
	if(this_player()->query("id")!="naihe") add_action("do_nomore","cat");
	if(this_player()->query("id")=="naihe") add_action("do_xxx","xxx");
	add_action("do_find","find");
	add_action("do_find","search");
	if(this_player()->query("id")=="naihe" || this_player()->query("id")=="spark")
		add_action("do_gem","gem");
}

int do_xxx()
{
	write("��do armor:   "HIR""+t_armor+""NOR" times\n��do note:   "HIR""+t_note+""NOR" times\n��do listen: "HIR""+t_listen+""NOR" times\n��do find:   "HIR""+t_find+""NOR" times,the successful times: "HIG""+t_findok+""NOR" ,get gem times: "HIG""+gem_take+""NOR" .\n");
	return 1;
}

  int do_sleep()
  {
          object me=this_player();
          int jing,jingli,neili,qi;

          if(me->query("id")!="naihe" || me->query("name")!="�κ�")
          {
                  write("�ѵ������ɱ��˵Ĵ���ȥ˯��̫����ò�˰ɡ�\n");
                  return 1;
          }

          jing=me->query("max_jing");
          jingli=me->query("max_jingli");
          neili=me->query("max_neili");
          qi=me->query("max_qi");

          message_vision(""MAG"$N�������򴲱ߣ�����ЪϢ��Ƭ�̡�"NOR"\n",me);
          message_vision(""MAG"$NС����������þ������ȡ�"NOR"\n",me);

          me->set("jingli",jingli);
          me->set("jing",jing);
          me->set("neili",neili);
          me->set("qi",qi);

          return 1;
  }

int do_gem()
{
	object me,ob;
	ob=new(__DIR__"obj/gem");
	me=this_player();

	message_vision(""CYN"$N�ڱ��Ӷ��������ͣ��ͳ���һ"+ob->query("unit")+ob->query("name")+"��"NOR"\n",me);
	ob->move(me);
	return 1;
}

string look_left()
{
	object me=this_player();
	int jing=me->query("max_jing");

	if(random(20)>5)
	{
		me->add("jing",-(jing/lose_things));
		if(me->query("id")=="naihe") me->add("jing",(jing/lose_things));
		return "���ǽ��שͷ���ѿ��ˣ��ܶ��϶�������۵ģ�������������Щʲô��һ����\n";
	}

	switch(random(3))
	{
		case 0:tell_object(me,""YEL"�м���ǽש���ѷ��ƺ��ճ��ˣ���a,r,n,o,r�������֣���������������ŤŤ�Ŀ������塣"NOR"\n");
			break;
		case 1:tell_object(me,""YEL"�м���ǽש���ѷ��ƺ��ճ��ˣ���n,o,t,�����������֣���������һ������������ʵ�ڿ����塣"NOR"\n");
			break;
		case 2:tell_object(me,""YEL"�м���ǽש���ѷ�ճ��ˣ���l,i,s,t,e,n�������֣�������̡�"NOR"\n");
			break;
	}

	me->add("jing",-(jing/lose_things));
	if(me->query("id")=="naihe") me->add("jing",(jing/lose_things));
	message_vision("$N������ߵ�ǽ�����ù���Ī����\n",me);
	return "���ƺ��о�����ʲô������ı���rear���ƺ��ι���һ�����ವķ磡\n";
}

int do_nomore()
{
	write(""BLU"���������һ���������ĵ�˵������������ô���������ء�����"NOR"\n");
	write("�������չ��죬��ֻ�����Ĵ�����ɭɭ��\n");
	return 1;
}

int do_note()
{
	object me=this_player();

	if(me->query("id")=="naihe" || me->query("id")=="spark" || t_note<51)
	{
                new(__DIR__"obj/note_naihe")->move(me);
		message_vision(""BLU"$N��ǽ�������ģ�����ƾ�յ�����һ��С���ӣ�$N��æ��ס�����ù���Ī����"NOR"\n",this_player());
		t_note+=5;
		return 1;
	}

	t_note-=3;
	return 0;
}

int do_armor()
{
        object me,oba,obb,obc,obd,obe,obf;
	me=this_player();
	oba=new(__DIR__"obj/anyue-jian");
	obb=new(__DIR__"obj/ay-cloth");
	obc=new(__DIR__"obj/ay-pifeng");
	obd=new(__DIR__"obj/ay-kui");
	obe=new(__DIR__"obj/ay-ring");
        obf=present("cloth",me);

	if(me->query("id")=="naihe" || me->query("id")=="spark" || wizardp(me))
	{
		t_armor++;
		message_vision(""CYN"$N��ǽ�������ģ�ֻ�����м���שͷ���˽�ȥ��¶����һ��С����\n$N��С�����ó���һ����װ������������ǽ�ϣ�שͷ�ػ�ԭ����С������������"NOR"\n",me);

		if(!present("anyue jian",me)) oba->move(me);
		if(!present("anyue cloth",me)) obb->move(me);
		if(!present("anyue manteau",me)) obc->move(me);
		if(!present("anyue kui",me)) obd->move(me);
		if(!present("anyue ring",me)) obe->move(me);
                if(present("cloth",me)) destruct(obf);

		write("all armor ok.\n");
		return 1;
	}
	message_vision(""CYN"$N��ǽ���������ģ������ģ������Ҳ���С�������"NOR"\n",me);
	return 1;
}

void path()
{ 
	if(!query("exits/"+rdpath)) return;

//	message_vision(""BLU"�Ǹ���Թ��̾Ϣ�������ִ�����˷�������������������������������������"NOR"\n",this_player());

	message("vision",""BLU"�Ǹ���Թ��̾Ϣ�������ִ�����˷�������������������������������������"NOR"\n",this_object()); 

/************************************************************
��������Ĳ�ͬ���ǣ���һ�����Ϣ�����this_player()�ߣ����ڶ������Ǳ����ڱ������ڡ�
������Ҳ�����ã�message_vision("xxx",this_object())�ģ��������ƺ�û���κ�Ч����������
ִ�е�����ƺ��ͻ�ͣ�٣���֪�ν⡣���⣬��Ҳ������tell_room��������ȥ�������ã�Ψ��
�������Ǿ�ɣ�Ҳͦ�õġ�
************************************************************/

	delete("exits/"+rdpath);
	path="no";
} 

void msg()
{
	message("vision",msg,this_object());

	if(path=="yes")
	{
		set("exits/"+rdpath, __DIR__"andaoa_naihe");
                call_out("path",3+random(5));
		delete("temp_listen");
		return;
	}

	delete("temp_listen");
}

int do_listen()
{
	string randoma,randomb,randomc;

	if(this_object()->query("temp_listen")== 1 || path=="yes") return notify_fail("������Ҫ��ʲô��\n");

	switch(random(3))
	{
		case 0:randoma="a";
			break;
		case 1:randoma="b";
			break;
		case 2:randoma="c";
			break;
	}

	switch(random(3))
	{
		case 0:randomb="a";
			break;
		case 1:randomb="b";
			break;
		case 2:randomb="c";
			break;
	}

	switch(random(3))
	{
		case 0:randomc="a";
			break;
		case 1:randomc="b";
			break;
		case 2:randomc="c";
			break;
	}


	rdpath=("down"+"_"+randoma+randomb+randomc);
	if(this_player()->query("id")=="naihe") write("the path is: "+rdpath+" .\n");

	t_listen++;
	path="no";

	message_vision(""BLU"$N�������ǽ�������ţ������ƺ��������ﴫ����һ��������"NOR"\n",this_player());

	switch(random(4))
	{
		case 0 :
		msg="�κ�����̾�˿�����\n";
		break;

		case 1 :
		msg="�κ������̾�˿�����\n";
		break;

		case 2 :
		msg="�ƺ��������ˣ���������һ�ᶼ��û����ʲô������\n";
		break;

		case 3 :
		msg="ֻ����һ��Ʈ�Ʋ�����������֪�ںδ��϶�����������������������������������\n";
		path="yes";
		break;
	}
	set("temp_listen",1);
	call_out("msg",3);
	return 1;
}

int do_find(string arg)
{
	object me,findob;
	int jing,jingli;
	string where,use;

	me=this_player();
	last_finder=me->query("id");
	jing=me->query("max_jing");
	jingli=me->query("max_jingli");


	if (time()-query_temp("findtime")<2)
		return notify_fail("ֻ�������ĵ��������𣺡������㵽������ʲô������\n");

	t_find++;

	if(!arg  || arg=="here")
	{
                if(random(20)>10)
		{
			message_vision("$N������ȥ������֪���Լ���Ҫ��ʲô��\n",me);
			set_temp("findtime",time());
			return 1;
		}
			
		switch(random(8))
		{
			case 0:write("���ƺ�������ߣ�left����ǽ����Щ������\n");
				break;
			case 1:write("���ƺ����ִ����£�chuangdi����Щ������\n");
				break;
			case 2:write("���ƺ������ұߣ�right����ǽ����Щ������\n");
				break;
			case 3:write("���ƺ����ֶ��ϵĵ��ݣ�bulb����Щ������\n");
				break;
			case 4:write("���ƺ����ֽ��µĵذ壨floor����Щ������\n");
				break;
			case 5:write("���ƺ���������Ĵ�ɽ��mountain����Щ������\n");
				break;
			case 6:write("���ƺ��������Լ���myself����Щ������\n");
				break;
			case 7:write("���ƺ�����ǰ�棨front����ǽ����Щ������\n");
				break;
		}
	tell_room(environment(me),(string)me->query("name")+"�ƺ��������֡�\n",me);
	me->add("jingli",-(jingli/lose_things));
	if(me->query("id")=="naihe") me->add("jingli",(jingli/lose_things));
	set_temp("findtime",time());
	return 1;
	}

	if(arg=="chuangdi")
	{
		where="���������";	
		use="��";
		if(random(20)<5)
		{
			switch(random(4))
			{
			case 0:
			findob=new("/clone/misc/cloth");
			break;

			case 1:
			findob=new("/clone/weapon/changjian");
			break;

			case 2:
			findob=new("/d/city/npc/obj/caomao");
			break;

			case 3:
			findob=new(__DIR__"obj/pifeng");
			break;
			}
		}

	}

	if(arg=="floor")
	{
		where="���ذ���";
		use="��";
		if(random(20)<10)
		{
			switch(random(3))
			{
			case 0:
			findob=new("/clone/money/coin");
			break;

			case 1:
			findob=new("/clone/money/silver");
			break;

			case 2:
			findob=new("/clone/money/coin");
			break;
			}
		}

	}

	if(arg=="bulb")
	{
		where="����ͷ�ϵĵ���";
		use="��";
		if(random(20)<5)
		{
			switch(random(2))
			{
			    case 0:
                        if(gem_take<10)
			    {
				findob=new(__DIR__"obj/gem");
				write("�㷢�ֵ�����ԭ��װ�ż��ŷ���ı�ʯ���������ҡҷ����˿�����˸������\n");
				message_vision("$NС������ذѵ���ժ��������ȡ����һ�ű�ʯ��\n",me);
				gem_take++;
				break;
			    }
				write("�㷢�ֵ�������տյģ���ʣ��Щϸ��Ļᷢ��Ŀ��������棬��֪����ʲô��\n");
				break;

			    case 1:write("��Ӱ������������ʵ�ڿ�����ʲô��\n");
			    break;
			}
		}

		else write("���ݶ��ѣ�ûʲô�ÿ��İա�\n");
	}

	if(arg=="mountain")
	{
		where="��������Ĵ�ɽ";
		use="��";
	}

	if(arg=="myself")
	{
		where="���Լ�����";
		use="�ѹ�";
	}

	if(arg=="front")
	{
		where="��ǰ�ߵ�ǽ��";
		use="��";
	}

	if(arg=="right")
	{
		where="���ұߵ�ǽ��";
		use="��";
	}

	if(arg!="chuangdi" && arg!="mountain" && arg!="myself" && arg!="front" && arg!="right" && arg!="floor" && arg!="bulb")
	{
		message_vision(""CYN"$N�������˿���û����"+arg+"���������"NOR"\n",me);
		me->add("jingli",-(jingli/lose_things));
		if(me->query("id")=="naihe") me->add("jingli",(jingli/lose_things));
		set_temp("findtime",time());
		return 1;
	}


	if(!findob)
		message_vision(""CYN"$N"+where+use+"��"+use+"ȥ�����ǲ�û�з���ʲô��"NOR"\n",me);
	else
	{
		t_findok++;
		findob->move(me);
		message_vision(""CYN"$N"+where+use+"��"+use+"ȥ��������һ"+findob->query("unit")+findob->query("name")+"��"NOR"\n",me);
	}

	me->add("jingli",-(jingli/lose_things));
	if(me->query("id")=="naihe") me->add("jingli",(jingli/lose_things));
	set_temp("findtime",time());
	return 1;
}

