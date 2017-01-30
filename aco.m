   function aco(l,w,n,ite)
     map(:,:)=ones(l,w); %0=obstacle 1=terrain
     phe0(:,:)=ones(l,w); %without food
     phe1(:,:)=ones(l,w); %with food
     map(:,w-20:w)=rand(l,21).*10;
     ants(:,:)=zeros(n,5);
     ants(:,1)=ones(n,1).*ceil(l/2);% x coord   %ceil(rand(n,1).*l);
     ants(:,2)=ones(n,1).*ceil(w/2);% y coord
     ants(:,3)=ones(n,1).*7; %facing direction
     ants(:,5)=zeros(n,1).*0; %status
     prob(:,:)=zeros(8,3);
     track(:,:)=zeros(l,w);
     %stage=1
     %sum(phe,2)
     i=1;
     for j=1:ite
       
       % ants
        
         for ant=1:n
             % 1 4 6  
             % 2   7
             % 3 5 8
            x=ants(ant,1);
            y=ants(ant,2);
            track(x,y)=100;
            prob(:,1)=[x-1;x;x+1;x-1;x+1;x-1;x;x+1];
            prob(:,2)=[y-1;y-1;y-1;y;y;y+1;y+1;y+1];
            for i=1:8
                if (prob(i,1)>(l-200) || prob(i,1)<200 || prob(i,2)>w || prob(i,2)<2)
                    prob (i,3)=0;
                    % 'hi'
                elseif (ants(ant,5)==0)
                    prob(i,3)=map(prob(i,1),prob(i,2))*phe1(prob(i,1),prob(i,2))/phe0(prob(i,1),prob(i,2));
                elseif (ants(ant,5)==1)
                    prob(i,3)=map(prob(i,1),prob(i,2))*phe0(prob(i,1),prob(i,2));
                end
                if (prob(ants(ant,3),3) ~=0)
                    prob(ants(ant,3),3)=prob(ants(ant,3),3)+2;
                end
            end
            mp=sum(prob(:,3));
            %mp
            %prob
            ch=ceil(rand()*mp);
            %if ch>mp 
             %   ch=mp;
            %end
            %ch
            %i=1;
            k=0;
            for i=1:8
                ch=ch-prob(i,3);
                %i
                if(ch<=0)
                    %k=i;
                    break;
                end
                %k
            end
            %i
            if(ants(ant,5)==0)
                phe0(x,y)=phe0(x,y)+200;
            end
            ants(ant,3)=i; % direction
            %ants(ant,4)=ants(ant,2);
            ants(ant,1)=prob(i,1);   %new location
            ants(ant,2)=prob(i,2);
         end
         
         
         phe0(:,:)=phe0(:,:)-0.1;
         base=(phe0<1).*0.5;
         phe0=phe0+base;
         phe1(:,:)=phe1(:,:)-0.20;
         base=(phe1<1).*0.5;
         phe1=phe1+base;
     end
         %DataAspectRatio=[1 1 ]
         subplot(221)
         image(map)
         subplot(222)
         image(phe0)
         subplot(223)
         image(phe1)
         subplot(224)
         image(track)
     %sum(phe,1)
end