// Code of ShenZhou
// xuan-nan.h for fight and get letter from Xuan

#include <ansi.h>

string* names = ({
	"chengxin luohan",
	"chengyi luohan",
	"chengsi luohan",
	"chengshi luohan",
	"chengzhi luohan",
	"chengxin luohan",
	"chengling luohan",
	"chengyu luohan",
	"chengshang luohan",
});

string ask_me()
{
        object fighter, room, monk;
	int j;

	fighter = this_player();

        if( !fighter->query_temp("xuanku-ready") )
                return RANK_D->query_respect(fighter) + 
                "�����������޺������������ʦ��ͬ�⡣";

        if( stringp(query_temp("busyfor")) ) {
                if( (string)query_temp("busyfor") != fighter->query("id") )
                return RANK_D->query_respect(fighter) + 
                "��������������ս�޺��������һ��ʱ�������ɡ�";
                else
                return RANK_D->query_respect(fighter) +
                "���������Ѿ�׼��������";
        }

        say("\n����˵�����ðɣ������ټ������ó������������䳡���ϣ����Ժ����������䳡�ϵ��㡣\n");

        message_vision("\n���Ѵ�ʦ�����뿪��\n\n", fighter);

        for(j=1; j<10; j++) {
                if(!( room = find_object("/d/shaolin/banruo" + j)) )
                room = load_object("/d/shaolin/banruo" + j);
                
  		move(room);           
		if( !objectp(monk = present(names[j-1], room)) ) {
	        	move("/d/shaolin/banruo5");
        	        message_vision("\n���Ѵ�ʦ���˹�����\n\n", fighter);
			return "���ǶԲ��𣬰����������˲��ڣ��޷������޺�����";	
		}
     /*  Disable by lisser

                if( monk->query("jing")*10 < monk->query("max_jing")*8
                ||  monk->query("qi")*10 < monk->query("max_qi")*8
                ||  monk->query("neili")*10 < monk->query("max_neili")*5 ) {
                        move("/d/shaolin/banruo5");
        	        message_vision("\n���Ѵ�ʦ���˹�����\n\n", fighter);
                        return "���ǶԲ��𣬰���������λ�������岻�ʣ��޷������޺�����";
                }
     */

                message("vision", "\n���Ѵ�ʦ���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
                message("vision", monk->query("name") + "�޺����˵�ͷ���첽���˳�ȥ��\n", room, monk);
                monk->move("/d/shaolin/wuchang1");
	}

        move("/d/shaolin/banruo5");
        message_vision("\n�����ʦ���˹�������$N˵���������ó����Ѿ������������䳡��\n", fighter);
        message_vision("\n���Ѵ�ʦ�����뿪��\n\n", fighter);
        move("/d/shaolin/wuchang");
        message_vision("\n���Ѵ�ʦ���˹�����\n\n", this_object());

        if( objectp(monk = present("xuanku dashi", environment())) )
        message_vision("\n���Ѵ�ʦ�������ʦ���˵�ͷ��\n\n", this_object());

        fighter->set_temp("xuannan-ready", 1);
        set_temp("busyfor", fighter->query("id"));
	return "�ã���Ҷ������ˡ�\n";
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "��") )
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query("luohan_winner") )
		{
			command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɳ��ֱ��޺�֮һ !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û�д���ʮ���޺����󣬲���Խ����ʦ��");
			return;
		}
	}

	return;
}
