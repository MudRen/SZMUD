//Cracked by Roath

inherit NPC;
string* menpai = ({
	"��ͯ˵����\n",
	"         \n",
	"         \n",
	"         \n",
	"         \n",
});
int ask_menpai(string* message);

	set("inquiry", ([
			"�䵱"   :  (: ask_menpai, menpai:),
		]));

void greeting(object me)
{	
	say("��ͯЦ��˵������λ" + 
			RANK_D->query_respect(me) + "\n");
	say("��ͯ˵��������ʲ���������Ҿͺ�����(ask dao about �䵱) \n");
	say("         ��(help wudang)��\n");
 }

#include "/d/xiakedao/npc/xkdnpc.h"