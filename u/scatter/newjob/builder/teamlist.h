//����������
//Lara 2001/11/09
string *member = ({
"�鳤�����Ÿ���Ա�����Ϳ��ƹ��̽��ȣ�����job", "jiuer", 
"����������ϸ�ڹ滮������room", "lara",
"Ŀǰ��δ��ӣ�������", "piao",
"�߼���̣�����skill��quest", "mariner",
"�ռ����Ϻͱ�̣�����npc��obj", "fywen",
"����","buwu",
"�߼���ı","hongyan",
"�߼���ı","naihe",
"����","xbuwu",
});

int is_member(object me)
{
        int i;

        for(i=0; i<sizeof(member); i++)
                if ( me->query("id") == member[i] )     return 1;

        return 0;
}
