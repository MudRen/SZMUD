//                ��׼��������ʾ��                                   |
// ������Ϸ��Ŀ  ��ȭ  ��dc_huaquan.c
// by naihe  2002-06-02  ��ï��

/****************************************************************

        ��ʦע�⣺������Ϸʱ�������뿪�������Լ��͡�ץ�κ�
                  ��Ϸ������뿪��������δ֪���󣬻���δ
                  ֪Ц�����֣�����

        ����Ϸ�����жϳ�ʽ������������ʦ���ҵ�����������κ���
        ��ʦץ�ˡ�ǹ�С�smash����ɵĴ����Ц����naihe�Ų�����  : )
*****************************************************************/


#include <ansi.h>
inherit ROOM;

string look_paizi();
void one_player();
void two_player();
void win_lose();
void money_jisuan();
void reset_games();


string pler_a,pler_b,tempnamea,tempnameb,tempida,tempidb,tempusea,tempuseb,games,winner,
tempusea="none",
tempuseb="none",
tempnamea="none",
tempnameb="none",
winner="none",
games="free";

int one_times,two_times,one_bet,two_bet,t_out,wait_time,temp,bet,same_times,
wait_time=10;


void create()
{
	set("short", HIC"������Ϸ�䡤��ȭ��Ϸ"NOR);
	set("long", "���Ǹ�С���䣬�տյ�ֻ��������ͷ�ڷ���һ����֪ʲô���õĻ���������
��ǰ������һ�����ӣ��о��ǻ���������ͨ�ĳ���ׯ��һ�㣬ȴ��֪���Ƕ�ʲô��
�����Ա�ǽ�Ϲ��ŵ�С���ӣ�paizi�� ��д��һЩ���������С�֣�������Ĵ�
�����̲�ס��ȥ��������\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi": (: look_paizi :),
	]));

	set("exits", ([
	    "south": __DIR__"dc_kill",
	    ]));

	setup();
}

void init()
{
	if (wizardp(this_player()))  add_action("do_xxx", "xxx"); // wiz ���Բ�ѯ��ֵ��
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_huaquan","huaquan");
	add_action("do_ck","ck");
	add_action("do_chu","chu");
	add_action("do_quit","quit");
	if(wizardp(this_player())) add_action("cannot_goto","goto");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

string look_paizi()
{
	write("
"HIY"������������������������������������������������������������������������������"NOR"
                               "HIW"��ȭ��Ϸ����˵��"NOR"

    ���� "HIY"huaquan <��ֵ> <����>"NOR" ��ʼ��Ϸ������Ϸֻ����1-10 gold��Ѻע��

"HIG"˫�˶Ծ�"NOR"����һλ�������������Ϸ֮����ȴ�"+wait_time+"���Խ�����һ��ҵı�����
�ڶ�λ��ҿ�������"HIY"<ck>"NOR"��ѯ��ǰ����ս���Լ�����ʱ��ֻҪ����"HIY"<huaquan>"NOR"��
����ʾ���ܴ˽���ʼ�Ծ�����Ҫע���������ϵĻƽ𶼲��������Զ�����

"HIG"������Ϸ"NOR"����һλ��Ϸ���ڵȴ�"+wait_time+"���������Ӧ�֣������Զ���ʼ������Ϸģʽ��

    ��Ϸ��ʼ������ "HIY"chu <��/��/��>"NOR" �������������ʽ�������໥���ƣ�"HIY"���ҽ���
���ƶܣ��ܵ���"NOR"���Ϳ�����������������Ϸʱ����Ϊ1��1��˫����Ϸʱ���������
�以���Զ�ת�ʡ�

"HIR"ע�⣺"NOR"
��Ϸ�У������뿪�����䣻��ʼ���к���"+wait_time+"�����Բ����У�����ϵͳ�Զ���ȡ��ʽ��
����Ϸ�����������������5�ֶ�������ͬʱ�����ѵ���Ѻע����ȡ���������á�

                                                   "HIG"--by naihe  2002-06-02"NOR"
"NOR+HIY"������������������������������������������������������������������������������"NOR"\n");
	if(wizardp(this_player())) write("��ʦ������<xxx>ָ��鿴���ڵ���Ϸͳ�ơ�\n");
	message_vision(CYN"$N��ǽ�Ϲ��ŵ�˵����ȥ��һ����Ȼ��������ӡ�\n"NOR,this_player());
	return "���һ�ֶԾ���Ϸ��"HIW""+pler_a+""NOR"սʤ��"HIW""+pler_b+""NOR"�����Ϊ"HIW""+bet+""NOR"���ƽ�\n";
}

int do_xxx()
{
	write("�ܵ�����Ϸ������"HIW""+one_times+""NOR"��Ѻע�ܶ"HIW""+one_bet+""NOR"�������ܶ"HIW""+t_out+""NOR"��\n��˫����Ϸ������"HIW""+two_times+""NOR"���ܽ��׶"HIW""+two_bet+""NOR"��\n���һ����"HIW""+pler_a+""NOR"սʤ��"HIW""+pler_b+""NOR"�����Ϊ"HIW""+bet+""NOR"���ƽ�\n");
	return 1;
}

int cannot_goto()
{
	if(this_player()->query_temp("duchang/huaquan"))
	{
		write("�㻹������Ϸ��������ȥ�����ⲻ�Ǵ��ĺ���ϷҪ��BUG��\n");
		return 1;
	}

	return 0;
}

int do_quit()
{
	if(this_player()->query_temp("duchang/huaquan"))
	{
		write("�㻹�ڶ�Ǯ�أ���ô�ܵ��ɲ��ðɡ�\n");
		return 1;
	}

	return 0;
}

int do_food()
{
	tell_object(this_player(), "�Ժ��뵽��¥������\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "��ô��������ʲô������һ����˵�ɡ�\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "���鿼״Ԫ����������滮ȭ��\n");
	return 1;
}

int do_huaquan(string arg)
{
	object me,qian;
	int temp_herea;
	string temp_hereb;

	me=this_player();
	qian=present("gold_money",me);

	if(games!="free" && games!="wait")
		return notify_fail("����������Ϸ���Ȼ���ɡ�\n");

	if(tempnamea=="none")
	{
	        if (!arg || sscanf(arg, "%d %s", temp_herea, temp_hereb) != 2)
			return notify_fail("ָ�huaquan <����> <����>\n");

		if(temp_hereb!="gold") return notify_fail("����ֻ���ûƽ�(gold)��������Ϸ��\n");
		if(temp_herea<0 || temp_herea>10) return notify_fail("����1�����10��������\n");
		if(!qian || (int)qian->query_amount()<temp) return notify_fail("�㲢û�д�����ô��Ǯ�գ���Ȼ���Ĳ�����Ʒ������ʵ��á�\n");

		same_times=0;
		temp=temp_herea;
		tempnamea=me->query("name");
		tempida=me->query("id");
		me->set_temp("duchang/huaquan","yes");
		message_vision(HIW"$N�ͳ�"+temp+"���ƽ�������һ�ӣ������µ�����˭�������һ���ȭ����\n"NOR,me);
		qian->add_amount(-temp);
// ��һλ������ϵ�Ǯ�Ѿ������ˣ�δͳ������ʷ��¼��

		games="wait";
		write("��ȴ�"+wait_time+"���Ա�������Ҽ��롣\n");
		call_out("one_player",wait_time);
		return 1;
	}

	if(me->query("id")==tempida) return notify_fail("���Ѿ����µ������ˣ���һ����ɡ�\n");
	if(!qian || (int)qian->query_amount()<temp) return notify_fail("�㲢û�д�����ô��Ǯ�գ���Ȼ���Ĳ�����Ʒ������ʵ��á�\n");

	tempnameb=me->query("name");
	tempidb=me->query("id");
	me->set_temp("duchang/huaquan","yes");
	message_vision(HIW"$N�ͳ���"+temp+"���ƽ�������һ�ӣ�Ҳ�����µ�����"+tempnamea+"������������㣡��\n\n"NOR,me);
	qian->add_amount(-temp);
// �ڶ�λ������ϵ�Ǯ�����ˡ���ʱ�������¼�������溯����һ���ټӡ�
	games="two_playing";
	message("vision",HIW"������Ϸ��"+tempnamea+"��"+tempnameb+"������"+wait_time+"���ڳ��аɣ�\n"NOR,this_object());
	message("vision",HIW"����"+wait_time+"�������룺chu <��/��/��> ��\n"NOR,this_object());
	call_out("two_player",wait_time);
	return 1;
}

int do_ck()
{
	if(games=="wait")
	{
		write("������"+tempnamea+"���µĵ�������"+temp+"���ƽ�Ҫӭս������<huaquan>�ɣ�\n");
		return 1;
	}

	write("����û��������Ϸ�����һ����"HIW""+pler_a+""NOR"սʤ��"HIW""+pler_b+""NOR"�����Ϊ"HIW""+bet+""NOR"���ƽ�\n");
	return 1;
}

int do_chu(string arg)
{
	object me=this_player();

	if(games=="free" || games=="wait") return notify_fail("�𼱣���Ϸ��û��ʼ�ء�\n");

	if(!arg || (arg!="��" && arg!="��" && arg!="��"))
		return notify_fail("��Ҫ��ʲô��   chu <��/��/��>  .\n");

	if(me->query("id")==tempida)
	{
		if(tempusea!="none") return notify_fail("�㲻�����������ô��������ġ�\n");

		message_vision(WHT"$N�����Ҫ��ʲô��ʽ�ˣ�����һ��Ц��\n",me);
		tempusea=arg;
		return 1;
	}

	if(me->query("id")==tempidb)
	{
		if(tempuseb!="none") return notify_fail("�㲻�����������ô��������ġ�\n");

		message_vision(WHT"$N�����Ҫ��ʲô��ʽ�ˣ�����һ��Ц��\n"NOR,me);
		tempuseb=arg;
		return 1;
	}

	message_vision(WHT"$N�������ţ�����"+arg+"����"+arg+"������Ҳ��֪�����ڶ�˭˵�ġ�\n"NOR,me);
	return 1;
}

void one_player()
{
	if(games!="wait")
	{
		if(games!="one_playing") return;

		if(tempusea=="none")
		{
                // ������ҳ�ʱ�ˣ�ϵͳ�Զ�������С�
			message_vision(WHT"$N������ȥ������ԥ�������ۿ�ʱ��Ҫ���ˣ��ŻŻ����ŵؾ�����һ�С�\n"NOR,this_player());
			switch(random(3))
			{
			    case 0:tempusea="��";
			    break;
			    case 1:tempusea="��";
			    break;
			    case 2:tempusea="��";
			    break;
			}
		}

// ����ϵͳ�Զ����С�
		switch(random(3))
		{
		    case 0:tempuseb="��";
		    break;
		    case 1:tempuseb="��";
		    break;
		    case 2:tempuseb="��";
		    break;
		}

		message_vision(HIY"�����﷢��һ��������"+tempuseb+"��\n"NOR,this_player());
		message_vision(HIY"$N�����е����ҳ�"+tempusea+"��\n"NOR,this_player());
		call_out("win_lose",1);
		return;
	}

	else
	{
		message("vision",HIW"ֻ����һ���������𣺡����������ɡ�������ԭ��ȴ�ǻ��������������\n"NOR,this_object());
	games="one_playing";
	write("����"+wait_time+"�������룺chu <��/��/��> ��\n");
	call_out("one_player",wait_time);
	}
}

void two_player()
{
	object plera,plerb;

	if(games!="two_playing") return; // ����ƺ�û��Ҫ��������Ҳû��ϵ����

// �κε��жϳ�ʽ�ƺ��������ˣ�����ֻ������д���������߾ȹ��ɡ�
	if(!this_player())
	{
		message("vision",HIW"\n��֪���ĸ���Ʒ��ô�ã��ĵ�һ���Ȼ�ܵ��ˣ����ֱ���ǿ����ֹ��\n\nѺע����ɱ�������ȡ���������á�\n"NOR,this_object());
		one_bet+=(temp*2); // one_bet �ľ��庬���ǣ�ϵͳ���룬����ֻ��������Ѻע���
		reset_games();
		return;
	}

// ���a��ʱ�ˣ�ϵͳ�Զ�������С�

	plera=present(tempida,environment(this_player()));
	plerb=present(tempidb,environment(this_player()));

// Ϊ�˷�ֹ��δ֪�Ĵ�����֣���˫����Ϸʱ����������ͬʱ���ڴ˴���ȷ��˵��
// Ӧ���ǡ���������ͬʱ����ͬһ���䡱����ǿ����ֹ��Ϸ��
	if(!plera || !plerb)
	{
		message("vision",HIW"\n��֪���ĸ���Ʒ��ô�ã��ĵ�һ���Ȼ�ܵ��ˣ����ֱ���ǿ����ֹ��\n\nѺע����ɱ�������ȡ���������á�\n"NOR,this_object());
		one_bet+=(temp*2); // one_bet �ľ��庬���ǣ�ϵͳ���룬����ֻ��������Ѻע���
		reset_games();
		return;
	}

	if(tempusea=="none")
	{
		message_vision(WHT"$N������ȥ������ԥ�������ۿ�ʱ��Ҫ���ˣ��ŻŻ����ŵؾ�����һ�С�\n"NOR,plera);
		switch(random(3))
		{
		    case 0:tempusea="��";
		    break;
		    case 1:tempusea="��";
		    break;
		    case 2:tempusea="��";
		    break;
		}
	}

// ���b��ʱ�ˣ�ϵͳ�Զ�������С�
	if(tempuseb=="none")
	{
		message_vision(WHT"$N������ȥ������ԥ�������ۿ�ʱ��Ҫ���ˣ��ŻŻ����ŵؾ�����һ�С�\n"NOR,plerb);
		switch(random(3))
		{
		    case 0:tempuseb="��";
		    break;
		    case 1:tempuseb="��";
		    break;
		    case 2:tempuseb="��";
		    break;
		}
	}
	message_vision(HIY"$N�����е����ҳ�"+tempusea+"��\n"NOR,plera);
	message_vision(HIY"$N�����е����ҳ�"+tempuseb+"��\n"NOR,plerb);
	call_out("win_lose",1);
	return;
}

void win_lose()
{
	object ob=this_object();
	string temp_miaoshu,winner_name;

	message("vision",HIW"�����ˣ�����\n"NOR,ob);

	if(games=="one_playing") tempidb="robot_naihe";

	if(tempusea==tempuseb)
	{
		same_times++;
		if(same_times>=5)
		{
			message("vision",HIW"��"+same_times+"�֣����ߵ���ʽ��Ȼһ����������Ϸǿ�Ƚ���������Ѻע���ɻ�����ȡ���������ã�лл��\n"NOR,ob);
			if(games=="one_playing") one_bet+=temp;
			if(games=="two_playing") one_bet+=(temp*2);
			reset_games();
			return;
		}

		message("vision",HIW"���߳�����ʽ��һ��������5���ھ������ٱ�һ�Σ�����\n"NOR,ob);
		tempusea="none";
		tempuseb="none";

		if(games=="one_playing")
		{
			call_out("one_player",5);
			return;
		}

		if(games=="two_playing")
		{
			call_out("two_player",5);
			return;
		}
	}

	if(tempusea=="��" && tempuseb=="��")
	{
		temp_miaoshu="���ҽ�";
		winner=tempida;
	}

	if(tempusea=="��" && tempuseb=="��")
	{
		temp_miaoshu="�ܵ���";
		winner=tempidb;
	}

	if(tempusea=="��" && tempuseb=="��")
	{
		temp_miaoshu="���ҽ�";
		winner=tempidb;
	}

	if(tempusea=="��" && tempuseb=="��")
	{
		temp_miaoshu="���ƶ�";
		winner=tempida;
	}

	if(tempusea=="��" && tempuseb=="��")
	{
		temp_miaoshu="���ƶ�";
		winner=tempidb;
	}

	if(tempusea=="��" && tempuseb=="��")
	{
		temp_miaoshu="�ܵ���";
		winner=tempida;
	}

// ����ִ����ʤ���жϡ����½�������һ�������и����жϡ�

	if(winner==tempida) winner_name=tempnamea;
	if(winner=="robot_naihe") winner_name="��������";
	else if(winner==tempidb) winner_name=tempnameb;

	message("vision",""HIW""+temp_miaoshu+"�����ֱ���"+winner_name+"ʤ���Ľ���"+temp+"���ƽ�\n"NOR,ob);

	money_jisuan();
}

void money_jisuan()
{
	object plera,plerb,jiangjin,qiana,qianb;

	jiangjin=new("/clone/money/gold");

	if(!this_player())
	{
		message("vision",HIW"\n��֪���ĸ���Ʒ��ô�ã��ĵ�һ���Ȼ�ܵ��ˣ����ֱ���ǿ����ֹ��\n\nѺע����ɱ�������ȡ���������á�\n"NOR,this_object());
		one_bet+=(temp); // one_bet �ľ��庬���ǣ�ϵͳ���룬����ֻ��������Ѻע���
		reset_games();
		return;
	}

	plera=present(tempida,environment(this_player()));
	plerb=present(tempidb,environment(this_player()));

	jiangjin->set_amount(temp*2);
	if(plera) qiana=present("gold_money",plera);
	if(plerb) qianb=present("gold_money",plerb);

// ������Ϸʱ�����жϡ�
	if(games=="one_playing")
	{
		one_times++;
		one_bet+=temp;  // ��䣬�Ȳ�����Ӯ���ѵ�����Ϸ��ѹע��¼�ۼӡ�
// ���ʤ����
		if(winner==tempida)
		{
		    t_out+=(temp*2); // ��䣬ͳ�Ƶ�����Ϸ�Ľ����ۼӡ�



  // log �ļ���¼��
                  log_file("duchang/HUAQUAN_GAME", sprintf("%s(%s)��%s�滮ȭ��ϷӮ�ý��� %d ���ƽ�\n",
                  this_player()->query("name"), getuid(this_player()), ctime(time()), temp));


// �����ûǮ��ֱ��move����Ǯ����ͼ��ϵ��ˡ�����ж�ʽ��Ϊ�˷�ֹ
// δ֪����ġ�

		    if(!plera)
		    {
			message("vision",""HIW""+tempnamea+"��֪������ȥ�ˣ���˼���ǲ�Ҫ�����ˡ�\n��������֧�֡�ûϣ�����̡����ɱ��������ͣ�лл��\n"NOR,this_object());
			one_bet+=temp;
			reset_games();
			return;
		    }

		    if(!qiana) jiangjin->move(plera);
		    else qiana->add_amount(temp*2);
		}
		reset_games();
		return;
	}

	if(games=="two_playing")
	{
		two_times++;
		two_bet+=temp;

		if(winner==tempida)
		{
		    if(!plera)
		    {
			message("vision",""HIW""+tempnamea+"��֪������ȥ�ˣ���˼���ǲ�Ҫ�����ˡ�\n��������֧�֡�ûϣ�����̡����ɱ��������ͣ�лл��\n"NOR,this_object());
			one_bet+=(temp*2);
			reset_games();
			return;
		    }
		    if(!qiana) jiangjin->move(plera);
		    else qiana->add_amount(temp*2);
		    pler_a=tempnamea;
		    pler_b=tempnameb;
		}

		else
		{
		    if(!plerb)
		    {
			message("vision",""HIW""+tempnameb+"��֪������ȥ�ˣ���˼���ǲ�Ҫ�����ˡ�\n��������֧�֡�ûϣ�����̡����ɱ��������ͣ�лл��\n"NOR,this_object());
			one_bet+=(temp*2);
			reset_games();
			return;
		    }
		    if(!qianb) jiangjin->move(plerb);
		    else qianb->add_amount(temp*2);
		    pler_a=tempnameb;
		    pler_b=tempnamea;
		}

		bet=temp;
		message("vision",""HIW""+pler_a+"����������Ц�������������ϵĻƽ�ɨ����С�\n"NOR,this_object());
		reset_games();
	}
}

void reset_games()
{
	object plera,plerb;

	plera=present(tempida,environment(this_player()));
	plerb=present(tempidb,environment(this_player()));

	if(plera) plera->delete_temp("duchang/huaquan");
	if(plerb) plerb->delete_temp("duchang/huaquan");
	games="free";
	tempnamea="none";
	tempnameb="none";
	tempida="1";
	tempidb="1";
	tempusea="none";
	tempuseb="none";
	winner="none";
	same_times=0;
	temp=0;
	message("vision",HIW"��Ϸ�����ˡ�\n"NOR,this_object());
	return;
}

int valid_leave(object me, string dir)
{
	if(this_player()->query_temp("duchang/huaquan"))
		return notify_fail("�㻹�ڶ�Ǯ�أ���ô�ܵ��ɲ��ðɡ�\n");
        return ::valid_leave(me, dir);
}

