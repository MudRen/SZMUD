// Code of ShenZhou
// rankd.c
// 1996-02-15 dts ranking related to "shen"
// 1996-11-26 xbc added emei ranking
// 2001-7-12  add by rider
// 2001-7-27  huaishi ������ʦ rank 
#include <ansi.h>

string query_rank(object ob)
{
	int shen;
	int budd;
	int rank;
	int lama;
	int maha;
	int pixie;
	int dlrank;
	int taoism;

	if( ob->is_ghost() )
		return HIB "�� ��  �� ��" NOR;

	shen = ob->query("shen");

	if ( ob->query("family/family_name") == "������" )
		budd = ob->query_skill("buddhism",1);

	if ( ob->query("family/family_name") == "ؤ��" )
		rank = ob->query("rank");

	if ( ob->query("family/family_name") == "ѩɽ��" ||
		  ob->query("family/family_name") == "Ѫ����" )
		lama = ob->query_skill("lamaism",1);

	if ( ob->query("family/family_name") == "������" )
		maha = ob->query_skill("mahayana",1);

	//if ( ob->query("family/family_name") == "ȫ���" )
		taoism = ob->query_skill("taoism",1);

	if (ob->query("dali/employee"))
		dlrank = ob->query("dali/rank");

	// the following was to set class for those who became gonggong
	// before mongol add class eunuch
	//if ( ob->query("gender") == "����" )
	//	ob->set("class", "eunuch");
	// should be eunach.  The following lines can be removed
	// after Aug 1/97 , except that line of "pixie =...
	//	if ( ob->query("class")=="eunuch") ob->set("class","eunach");
	if (ob->query("class")=="eunach") {
		ob->delete("rank_info/respect");
		ob->delete("rank_info/rude");
	}
	pixie = ob->query_skill("pixie-jian", 1);
		  if (pixie<60 && ob->query("class")=="eunach") ob->delete("class");
	// remove the above line after 8/1/97, except the line of "pixie =..

	switch(ob->query("gender")) {
	case "Ů��":
		switch(wizhood(ob)) {
		case "(admin)":
			return HIW "�� ��  �� ��" NOR;
		case "(arch)":
                        return HIY "�� ��  �� ��" NOR;
		case "(wizard)":
                        return HIG "�� ��  �� ��" NOR;
		case "(virtuoso)":
			return HIC "���������ɡ�" NOR;
		case "(designer)":
                        return HIC "�� ��  �� ��" NOR;
                case "(caretaker)":
                        return HIG "���������ɡ�" NOR;
		case "(creator)":
			return YEL "�������ѡ��" NOR;
                case "(apprentice)":
                        return CYN "������ѧͽ��" NOR;
		case "(immortal)":
			return HIM "�� ��  �� ��" NOR;
		default:
			if( ((int)ob->query("PKS") > 100) &&
				((int)ob->query("PKS") > (int)ob->query("MKS")) )
				return HIR "�� ������ ��" NOR;
//			if( (int)ob->query("thief") > 10 )
//				return "�� ��  �� ��";
			switch(ob->query("class")) {
			case "bonze":
				if (maha >= 120 )
					return WHT "�� ���� ��" NOR;
				else if (maha >= 90)
					return WHT "�� ʦ��̫ ��" NOR;
				else if (maha >= 60)
													 return WHT "�� ������ ��" NOR;
				else if (maha >= 30)
													 return WHT "�� ɳ���� ��" NOR;
				else
					return WHT "�� ѧ��Ů ��" NOR;

		case "taoist":
			if (taoism >= 150)
				return HIW "�� Ů���� ��" NOR;
			else if (taoism >= 90)
				return HIY "�� ��Ů�� ��" NOR;
			else if (taoism >= 30)
				return HIG "�� Ů  �� ��" NOR;
			else
				return     "�� С���� ��" NOR;

			case "bandit":
				return "�� Ů���� ��";
			case "dancer":
				return "�� ��  �� ��";
			case "scholar":
				return "�� ��  Ů ��";
			case "officer":
				if (dlrank==5)
					return "�� ��  �� ��";
				else if (dlrank==4)
					return "��ھ�����ˡ�";
				else
					return "�� Ů  �� ��";
			case "fighter":
				return "�� Ů���� ��";
			case "swordsman":
				return "�� Ů��ʿ ��";
			case "alchemist":
				return "�� ��  ʿ ��";
			case "shaman":		
				return "�� ��  ҽ ��";
			case "beggar":		
				if (rank >= 9 && shen >= 100000)
					return HIG "�� Ů��ؤ ��" NOR;
				else if (rank >= 9 && shen <= -100000)
					return HIG "�� ħؤ�� ��" NOR;
				else if (rank >= 7 && shen >= 10000)
					return HIG "�� Ů��ؤ ��" NOR;
				else if (rank >= 7 && shen <= -10000)
					return HIG "�� ��ؤ�� ��" NOR;
				else if (rank >= 5 && shen >= 1000)
					return HIG "�� Ů��ؤ ��" NOR;
				else if (rank >= 5 && shen <= -1000)
					return HIG "�� ��ؤ�� ��" NOR;
				else if (rank >= 3 )
					return HIG "�� �л��� ��" NOR;
				else
					return HIG "�� �л��� ��" NOR;
			default:
				if (shen >= 1000000)
					return HIC "��������Ů��" NOR;
				else if (shen >= 100000)
					return HIC "�� ����Ů ��" NOR;
				else if (shen >= 10000)
					return HIC "�� ��  Ů ��" NOR;
				else if (shen >= 1000)
					return HIC "�� С��Ů ��" NOR;
				else if (shen <= -1000000)
													 return HIC "������ħŮ��" NOR;
				else if (shen <= -100000)
					return HIC "�� Ůħ�� ��" NOR;
				else if (shen <= -10000)
					return HIC "�� ��ħŮ ��" NOR;
				else if (shen <= -1000)
					return HIC "�� ħ  Ů ��" NOR;
				else if (shen <= -100)
					return HIC "�� СħŮ ��" NOR;
				else
					return "�� ��  Ů ��";
			}
		}
	default:
		switch(wizhood(ob)) {
		case "(admin)":
			return HIW "�� ��  �� ��" NOR;
		case "(arch)":
                        return HIY "�� ��  �� ��" NOR;
		case "(wizard)":
                        return HIG "�� ��  �� ��" NOR;
		case "(virtuoso)":
			return HIC "���������ɡ�" NOR;
		case "(designer)":
                        return HIC "�� ��  �� ��" NOR;
		case "(caretaker)":
                        return HIG "���������ɡ�" NOR;
		case "(creator)":
			return YEL "�������ѡ��" NOR;
		case "(apprentice)":
                        return CYN "������ѧͽ��" NOR;
		case "(immortal)":
			return CYN "�� ��  �� ��" NOR;
		default:
			if( ((int)ob->query("PKS") > 100)
			&&((int)ob->query("PKS") > (int)ob->query("MKS")) )
				return HIR "�� ��  �� ��" NOR;
//			if( (int)ob->query("thief") > 10 )
//				return "�� ��  �� ��";
			switch(ob->query("class")) {
			case "eunach":
				if (pixie >= 180)
					return HIM "�� ��ǧ�� ��" NOR;
				else if (pixie >= 160)
					return HIM "������ָ�ӡ�" NOR;
				else if (pixie >= 140)
					return HIM "�� ��ͷ ��" NOR;
				else if (pixie >= 120)
					return HIM "��������ͷ��" NOR;
				else if (pixie >= 100)
					return HIM "������ǧ����" NOR;
				else if (pixie >= 80)
					return HIM "�������ٻ���" NOR;
				else if (pixie >= 60)
					return HIM "������̫�ࡿ" NOR;
				else if (pixie >= 40)
					return HIM "�� ̫  �� ��" NOR;
				else if (pixie >= 20)
					return HIM "����Ʒ̫�ࡿ" NOR;
				else
					return HIM "�� С̫�� ��" NOR;
			case "bonze":
				if (budd >= 150)
					return HIY "�� ��  �� ��" NOR;
				else if (budd >= 120)
					return HIY "�� ʥ  ɮ ��" NOR;
				else if (budd >= 90)
					return HIY "�� ��  �� ��" NOR;
				else if (budd >= 60)
					return HIY "�� ��  �� ��" NOR;
				else if (budd >= 40)
					return HIY "�� ��  ʦ ��" NOR;
				else if (budd >= 30)
					return HIY "�� ��  �� ��" NOR;
				else
					return HIY "�� ɮ  �� ��" NOR;
			case "lama":
				if (lama >= 150)
					return HIY "�� ��  �� ��" NOR;
										  else if (lama >= 120)
					return HIY "�� ��  �� ��" NOR;
										  else if (lama >= 90)
													 return HIY "�� ��  ʦ ��" NOR;
				else if (lama >= 60)
					return HIY "�� ������ ��" NOR;
										  else if (lama >= 30)
													 return HIY "�� ��  �� ��" NOR;
				else
					return HIY "�� С���� ��" NOR;
			case "taoist":
				if (taoism >= 150)
					return HIW "�� ��  �� ��" NOR;
				else if (taoism >= 120)
					return HIC "����ѧ��ʦ��" NOR;
				else if (taoism >= 90)
					return HIM "����ѧ��ʦ��" NOR;
				else if (taoism >= 60)
					return HIY "�� ��  �� ��" NOR;
				else if (taoism >= 30)
					return HIG "�� ��  ʿ ��" NOR;
				else
					return     "�� С��ʿ ��" NOR;
			case "bandit":
				return "�� ��  �� ��";
			case "scholar":
				return "�� ��  �� ��";
			case "officer":
				if (dlrank==5)
					return "�� ��  ү ��";
				else if (dlrank==4)
					return "�� ��  ү ��";
				else if (dlrank==3)
					return "�� ��  �� ��";
				else if (dlrank<=2)
					return "�� ��  �� ��";
			case "fighter":		
				return "�� ��  �� ��";
			case "swordsman":	
				return "�� ��  ʿ ��";
			case "alchemist":	
				return "�� ��  ʿ ��";
			case "shaman":
				return "�� ��  ҽ ��";
			case "beggar":
				if (rank >= 9 && shen >= 100000)
					return HIG "�� ��  ؤ ��" NOR;
				else if (rank >= 9 && shen <= -100000)
					return HIG "�� ħ  ؤ ��" NOR;
				else if (rank >= 7 && shen >= 10000)
					return HIG "�� ��  ؤ ��" NOR;
				else if (rank >= 7 && shen <= -10000)
					return HIG "�� ��  ؤ ��" NOR;
				else if (rank >= 5 && shen >= 1000)
					return HIG "�� ��  ؤ ��" NOR;
				else if (rank >= 5 && shen <= -1000)
					return HIG "�� ��  ؤ ��" NOR;
				else if (rank >= 3 )
					return HIG "�� �л��� ��" NOR;
				else
					return HIG "�� С�л� ��" NOR;
			default:
				if (shen >= 1000000)
					return HIC "������������" NOR;
				else if (shen >= 100000)
					return HIC "�� ��  �� ��" NOR;
				else if (shen >= 10000)
					return HIC "�� ��  �� ��" NOR;
				else if (shen >= 1000)
					return HIC "�� ��  �� ��" NOR;
				else if (shen <= -1000000)
													 return HIC "������ħ����" NOR;
				else if (shen <= -100000)
					return HIC "�� ħ  �� ��" NOR;
				else if (shen <= -10000)
					return HIC "�� ��  ħ ��" NOR;
				else if (shen <= -1000)
					return HIC "�� ħ  ͷ ��" NOR;
				else if (shen <= -100)
					return HIC "�� ��  ħ ��" NOR;
				else
					return "�� ƽ  �� ��";
			}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ̫";
				else return "ʦ̫";
				break;

			case "taoist":
				if( age < 18 ) return "С�ɹ�";
				else return "�ɹ�";

			case "officer":
				if (ob->query("dali/rank")==5)
					return "����";
				else if (ob->query("dali/rank")==4)
					return "�����";
				else {
					if( age < 18 ) return "С����";
					else if( age < 50 ) return "����";
					else return "����";
				}
				break;
			default:
				if( age < 18 ) return "С����";
				else if( age < 50 ) return "����";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ��";
				else return "��ʦ";
				break;
			case "lama":
				if( age < 25 ) return "Сʦ��";
				else return "����";
				break;
			case "taoist":
				if( age < 18 ) return "С����";
				else return "����";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "С�ϵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ǰ��";
				break;
			case "eunach":
				if (ob->query_skill("pixie-jian",1)>160)
					return "����";
				if (age <18) return "С����";
				else if (age < 50) return "����";
				else return "�Ϲ���";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "��ү";
				else if (ob->query("dali/rank")==4)
					return "��ү";
				else if (ob->query("dali/rank")==3)
					return "����";
				else return "��ү";
				break;
			default:
				if( age < 20 ) return "С�ֵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ү��";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				return "����";
				break;
			case "taoist":
				return "��Ů";
				break;
			default:
				if( age < 18 ) return "С����";
				else if( age < 50 ) return "����";
				else return "����̫��";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "��ͺ¿";
				else return "��ͺ¿";
				break;
			case "lama":
				if( age < 50 ) return "��ͺ¿";
				else return "��ͺ¿";
				break;
			case "taoist":
				return "��ţ����";
				break;
			case "eunach":
				return "����";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "����";
				else if (ob->query("dali/rank")>=3)
					return "����";
				else return "������";
				break;
			default:
				if( age < 20 ) return "С���˵�";
				if( age < 50 ) return "����";
				else return "��ƥ��";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "СŮ��";
				else if( age < 50 ) return "���";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶɮ";
				else return "����";
				break;
			case "lama":
				if( age < 50 ) return "ƶɮ";
                                else return "����";
                                break;
			case "eunach":
				return "�¹�";
				break;
			case "taoist":
				return "ƶ��";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "С����";
				else return "�¹�";
				break;
			default:
				if( age < 50 ) return "����";
				else return "��ͷ��";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "������";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "�������";
				else return "�Ϻ�����";
				break;
			case "eunach":
				if (age < 50) return "����";
				else return "����";
				break;
			case "lama":
				if( age < 50 ) return "����ү";
				else return "�Ϸ�ү��";
				break;	
			case "taoist":
				return "��ɽ��";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "����";
				else if (ob->query("dali/rank")==4)
					return "����";
				else if (ob->query("dali/rank")==3)
					return "����";
				else return "��ү��";
				break;
			default:
				if( age < 50 ) return "��ү��";
				else return "����";
				break;
			}
	}
}
string query_close(object ob)
{
        int a1, a2;

	if (objectp(this_player()))
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
	 	a1 = previous_object()->query("age");
	 	a2 = ob->query("age");
	}
							
        switch (ob->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
	case "����" :
		if (ob->query("class")== "eunach") {
		if (a1 >= a2)
			if (random(5)==1) return "����";
			else return "�ܵ�";
		else
			if (random(5)==1) return "���";
			else return "���";
		}
	default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
                break;
        }
}

string query_self_close(object ob)
{
        int a1, a2;
	string gender;
	
	if( objectp(this_player()) )
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
		gender = this_player()->query("gender");
	} else 
	{	
       	 	a1 = previous_object()->query("age");
       	 	a2 = ob->query("age");
		gender = previous_object()->query("gender");
	}
		
        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
	}
}
